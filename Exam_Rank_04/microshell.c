#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	error(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return error ("error: cd: bad arguments\n");
	if (chdir(argv[1]) == -1)
		return error ("error: cd: cannot change directory to \n"), error(argv[1]), error("\n");
       return (0);
}

int	exec(char **argv, int i, char **envp)
{
	int	fd[2];
	int	status;
	int	pid;
	int	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (!has_pipe && !strcmp(*argv, "cd"))
		return cd(argv, i);
	if (has_pipe && pipe(fd) == -1)
		return error("error: fatal\n");
	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return error("error: fatal\n");
		execve(*argv, argv, envp);
		return error("error: cannot execute "), error(*argv), error("\n");
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return error("error: fatal\n");
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (argc > 1)
	{
		while(argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (i)
				status = exec(argv, i, envp);
		}
	}
	return (status);
}

