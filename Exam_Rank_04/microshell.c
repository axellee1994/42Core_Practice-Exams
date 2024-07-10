#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	err(char *str)
{
	write(2, str, strlen(str));
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
	{
		err("error: cd: cannot change directory to ");
		err(argv[1]);
		return (err("\n"));
	}
	return (0);
}

int	exec(char **argv, int i, char **envp)
{
	int	has_pipe;
	int	fd[2];
	int	status;
	int	pid;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd(argv, i));
	if (has_pipe && pipe(fd) == -1)
		return (err("error: fatal\n"));
	pid = fork();
	if (pid == -1)
		return (err("error: fatal\n"));
	if (pid == 0)
	{
		argv[i] = NULL;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1
				|| close(fd[1]) == -1))
			return (err("error: fatal\n"));
		execve(*argv, argv, envp);
		err("error: cannot execute ");
		err(*argv);
		return (err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1))
		return (err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec(argv, i, envp);
	}
	return (status);
}
