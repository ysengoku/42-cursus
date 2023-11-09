
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_ptr;
	size_t	i;

	dst_ptr = dst;
	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst_ptr);
}