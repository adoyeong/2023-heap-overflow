#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NameMax 10
#define PasswdMax 10
#define UsersMax 100
int main()
{
	FILE *fd;
	int i, mem, match;
	int num_users;
	char *passwd = (char*)malloc(sizeof(char)*PasswdMax);
	char *name = (char*)malloc(sizeof(char)*NameMax);
	char *PASSWDS = (char*)malloc(sizeof(char)*PasswdMax);
	char *USERS = (char*)malloc(sizeof(char)*NameMax);

	fd = fopen("/home/kali/securetest/passwd.txt", "r");
	if(fd == NULL)
	{
		fprintf(stdout, "\n[Error] Cannot find passwd file!\n");
		return -1;
	}
	fprintf(stdout, "\n[Program] Type UserName\n");
        fscanf(stdin, "%s", name);
	fscanf(fd, "%d", &num_users);
	match = 0;
	for(i=0; i<num_users; i++)
	{
		fscanf(fd, "%s", USERS);
		fscanf(fd, "%s", PASSWDS);
		if(strcmp(name, USERS) == 0)
		{
			match = 1;
			fprintf(stdout, "\n[Program] HELLO %s\n", name);
			fprintf(stdout, "\n[Program] Type your password\n");
			fscanf(stdin, "%s", passwd);
			if(strcmp(passwd, PASSWDS) == 0)
			{
				fprintf(stdout, "\n[Program] Password Match!\n");
			}
			else fprintf(stdout, "\n[Program] Password does not Match!\n");
			break;
		}
	}
	if(match ==0)
	{
		fprintf(stdout, "\n[Program] <%s> UserName does not match!\n", name);
		return 0;
	}
	free(USERS);
	free(PASSWDS);
	free(name);
	free(passwd);
	fclose(fd);
	return 0;
}
