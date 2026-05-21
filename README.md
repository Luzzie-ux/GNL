*This project has been created as part of the 42 curriculum by rodrpere*

# Table of contents

1. [Description](#description)
2. [Resources](#resources)
3. [Instructions](#instructions)
4. [Algorithm used](#algorithm-used)
	1. [What was implemented?](#what-was-implemented)
	2. [Why this way?](#why-this-way)
5. [Bonus](#bonus)
6. [Conclusion](#conclusion)


# Description

This C project revolves around reading line by line from a given file descriptor.  
It walks progressively towards the EOF (end of file), returning each line one by one as \n characters are found.  
The fuction get_next_line then, is the perfect way of achieving such requisits for our project.  

# Resources

In the making of this project, the resources used to do it were the GNU Debugger (GDB) and Claude Ai from Anthropic as debugging assistence and spelling mistakes. Valgrind to check for memory leaks and errors. Francinette made by [Xicodomingues](https://github.com/xicodomingues/francinette) to test every possible output. And the help of my peers to better understand what I was doing.

# Instructions

```bash

#To compile this project all you need to do this

cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c your_main.c

#the n for buffer_size indicates the amount of bytes the read function will read from the file descriptor given
 
```

# Algorithm used

## What was implemented?

To understand what was done here, we need first to dive into what the read function does and what the get_next_line itself will do.

```c 
//THE READ FUNCTION
ssize_t read(int fd, void *buf, size_t nbytes);
```

The read function will receive from the main a integer called file descriptor (int fd), that represents the file we are trying to read, beyond that it all comes to what the read function will do, depending on how many nbytes we give it, that is how many bytes the function will read from the file, the standard chosen by me was BUFFER_SIZE 42 (which can be found in the .h file with the same name as the project), but it doesn't matter the number of bytes chosen, as long as it is bigger than zero. Then whatever is read by the function will now be passed to our void *buf, storing up to nbytes of anything.

The function itself has three return values:

	A Positive one -> where nbytes > 0 (which means the read function worked).

	A Neutral one -> where nbytes = 0 (which means the read function has reached EOF).

	A Negative one -> where nbytes < 0 (which means the read function stopped reading).

with these values the get_next_line can do 50% of what we want it to do.

```c
//THE GET_NEXT_LINE
char	*get_next_line(int fd);
```

This function doesnt work alone, but what it essentily does is: 

It reads from the file given to a buffer, from that buffer we pass whatever it has stored to a static char* called stash, and from here we do two things.   

	First we will extract chars until we find a new_line and then return that as a variable called char *line.  

	Then, with stash still having the original line, we trim everything up to and including the \n, saving the remainder back into stash, repeating the loop until we reach EOF.  

With its process explained, lets see what makes it possible to do all that
	
In our get_next_line.h file we have these prototypes handling most of the work the gnl function calls for:

	int		ft_find_n(char *s); --> will search for a \n and if it does it return 1 for true 0 for false
	char	*get_next_line(int fd); --> will call the other functions
	char	*trim_stash(char *stash); --> will take the rest of the line after the first \n and return it
	size_t	ft_strlen(const char *s); --> will count the length of the string given
	char	*ft_strdup(const char *s); --> will duplicate the string given and return a malloc'd copy 
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
## Why this way?

The core challenge of get_next_line is that read doesn't stop at \n — it reads as many bytes as BUFFER_SIZE tells it to, meaning a single read can overshoot a newline and pull in characters that belong to the next line. This is why a static char *stash is necessary: it persists between calls, holding any leftover content beyond the first \n so nothing is lost. On the next call, get_next_line checks the stash before even calling read again — if a full line is already there, no read is needed at all.  

BUFFER_SIZE being a compile-time flag is intentional: a smaller value means more read calls but less memory usage, while a larger value does the opposite. Neither is universally better, so leaving it configurable makes the function more flexible.  

Finally, ft_strjoin freeing s1 is a deliberate choice to avoid memory leaks — since stash is constantly being rebuilt by joining old content with new buffer data, the old pointer must be freed each time or memory accumulates with every read cycle.  


# Bonus

For this project, the bonus part isnt that much complex, only asking us two thing, that we only call for 1 static variable and that our fuctions can handle multiple file descriptors at the same time.

```c
//gnl_bonus
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if ((fd < 0 || fd >= 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = fill_buffer(fd, stash[fd]);
	if (!stash[fd] || !*stash[fd])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extract_until_newline(stash[fd]);
	stash[fd] = trim_stash(stash[fd]);
	if (!stash[fd])
		stash[fd] = NULL;
	return (line);
}
```

By changing this part of the function to support the fd given by our main up until 1024, we make a limit of how many can be used. And by passing it to the rest of the helpers, we can do what the subject asks of us "This means you should be able to call get_next_line() to read from fd 3, then fd 4, then fd 5, then again from fd 3, then fd 4, and so forth, without losing track of the reading state for each file descriptor."

# Conclusion

The get_next_line is a deceptively simple function — on the surface it just reads a line, but getting it right requires careful thinking about memory management, buffer boundaries, and state persistence across calls. The static stash is what ties it all together, solving the core problem of read overshooting newlines without leaking memory or losing data.  

Beyond the function itself, this project was a valuable exercise in understanding how low-level I/O works in C, and why seemingly small decisions — like when to free a pointer or how large a buffer should be — have real consequences. It also reinforced the importance of testing edge cases: empty files, files with no trailing \n, and very large or very small buffer sizes all behave differently and need to be handled explicitly.  
