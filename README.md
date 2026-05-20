*This project has been created as part of the 42 curriculum by rodrpere*

# Description

This project revolves around the reading of files and saving which line was found within it.   
Walking progressevily towards the EOF(end of file), and returning one by one every \n we find.  
The fuction get_next_line then, is the perfect way of acheiving such requisits for our project.  

To check for instructions to go [Instructions](#instructions) 

# Instructions

```bash

#To compile this project all you need to do this

cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c your_main.c 

#the n for buffer_size indicates the amount of bytes the read function will read from fhe file descriptor given
 
```

# What was implemented?

To understand what was done here, we need first to dive into what the read function does and what the get_next_line itself will do.

```c 
//THE READ FUNCTION
ssize_t read(int fd, void *buf, size_t nbytes);
```

The read function will receive from the main a integer called file descriptor (int fd), that represents the file we are trying to read, beyond that it all comes to what the read function will do, depending on how many nbytes we give it, that is how many bytes the function will read from the file, the standard chosen by me was BUFFER_SIZE 42 (which can be found in the .h file with the same name as the project), but it doesnt matter the number of bytes chosen, as long as it is bigger than zero. Then whatever is read by the function will now be passed to our void *buf, storing up to nbytes of anything.

The function itself has three return values:

	one -> where nbytes > 0 (which means the read function worked).

	two -> where nbytes = 0 (which means the read function has reached EOF).

	three -> where nbytes < 0 (which means the read function stopped reading).

with these values the get_next_line can do 50% of what we want it to do.

```c
//THE GET_NEXT_LINE
char	*get_next_line(int fd);
```

This function by itself cant do anything, but what it basically does is. It reads from the file given to a buffer, from that buffer we pass whatever it has stored to a static char* called stash, and from here we do two things: 

First we will extract chars until we find a new_line and then return that as a variable called char *line.  

And then secondly with stash still having the original line, we will read from the \n found until the \0 at the end of the line, passing that to stash again and repeating the loop until we reach EOF.  

With its process explained, lets see what makes it possible to do all that
	
In our get_next_line.h file we have these prototypes handling most of the work the gnl function calls for:

	int		ft_find_n(char *s); --> will search for a \n and if it does it return 1 for true 0 for false
	char	*get_next_line(int fd); --> will call the other functions
	char	*trim_stash(char *stash); --> will take the rest of the line after the first \n and return it
	size_t	ft_strlen(const char *s); --> will count the lenght of the string given
	char	*ft_strdup(const char *s); --> will duplicate the string given and return a mallocated copy 
	char	*ft_strjoin(char *s1, char *s2); --> will join buffer to stash when no \n is found
	char	*fill_buffer(int fd, char *stash); --> will call the read function and fill buffer
	char	*extract_until_newline(char *stash); --> will extract from the string given a line until \n is found
	void	*ft_memcpy(void *dest, const void *src, size_t n); --> will copy memory from src to dest

the most important ones being fill_buffer, ft_strjoin, extract_until_newline and trim_stash:

```c
//fill_buffer

char	*fill_buffer(int fd, char *stash)
{
	char		*buffer;
	ssize_t		bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_find_n(stash))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(stash), stash = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash || !*stash)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}
```

```c
//ft_strjoin

char	*ft_strjoin(char *s1, char *s2)
{
	char		*new_string;
	size_t		total;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	total = len1 + len2;
	new_string = malloc(total + 1);
	if (!new_string)
		return (free(s1), NULL);
	ft_memcpy(new_string, s1, len1);
	ft_memcpy(new_string + len1, s2, len2);
	new_string[len1 + len2] = 0;
	return (free(s1), new_string);
}
```

```c
//extract_until_newline

char	*extract_until_newline(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash)
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (free(stash), NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = 0;
	return (line);
}
```

```c
//trim_stash

char	*trim_stash(char *stash)
{
	char	*rest_of_line;
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	l = 0;
	if (!stash)
		return (free(stash), NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = ft_strlen(stash);
	rest_of_line = malloc((j - i) + 1);
	if (!rest_of_line)
		return (free(stash), NULL);
	while (i != j)
		rest_of_line[l++] = stash[i++];
	rest_of_line[l] = 0;
	return (free(stash), rest_of_line);
}
```

# Why this way?

I believe that the way get_next_line was presented to me in the subject "your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time. (...) Your function should return the line that was read. If there is nothing left to read or if an error occurs, it should return NULL. Please note that the returned line should include the terminating \n character, except when the end of the file is reached and the file does not end with a \n character." was what made me choose to do it this way, with a simple mental loop where I save whatever was read from the file into a stash, then from this stash we co through the string until we find a \n, return that and from the original string we go through it and return whatever is after the first \n until the null character and repeat until EOF.

# Resources

In the making of this project, the resources used to do it were the GNU Degubber (GDB) and Claude Ai from Anthropic to debug the code. Valgrind to check for memory leaks and errors. Francinette made by [Xicodomingues](https://github.com/xicodomingues/francinette) to test every possible output. And the help of my peers to better understand what I was doing.
