
#Ressources
https://www.freecodecamp.org/news/flood-fill-algorithm-explained/
https://en.wikipedia.org/wiki/Flood_fill

To read from a file to a image object, you need either the XMP or PNG format. In order to read we can call the functions mlx_xpm_file_to_image and mlx_png_file_to_image accordingly. Do mind that mlx_png_file_to_image currently leaks memory. Both functions accept exactly the same parameters and their usage is identical.