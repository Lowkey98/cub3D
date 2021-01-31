int*	initialize_rgb(int *rgb)
{
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	return (rgb);
}
int		rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}