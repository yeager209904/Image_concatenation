# Concatenate Images

## Description
This program concatenates two images horizontally into a single output image file in PNG format. It uses the STB image library to load and save image files.

## Dependencies
- STB image library
  - stb_image.h
  - stb_image_write.h

## Usage
1. Compile the program using a C compiler (e.g., gcc) with the appropriate flags and dependencies:
   ```
   gcc -o concatenate_images concatenate_images.c -lm
   ```
2. Run the compiled program from the command line with the filenames of the two images to be concatenated as arguments:
   ```
   ./concatenate_images image1.png image2.png
   ```

## Functionality
- Loads two input images specified by command-line arguments.
- Calculates output image dimensions based on input image dimensions.
- Allocates memory for output image pixel data.
- Copies pixel data of the first image to the output image.
- Copies pixel data of the second image to the output image, ensuring concatenation.
- Saves the output image as "output.png" using stbi_write_png().
- Frees memory allocated for loading images to prevent memory leaks.

## Note
- Input images are assumed to be in PNG format.
- The output image will be saved as "output.png" in the same directory as the program.

## Example
```
./concatenate_images image1.png image2.png
```
This command concatenates "image1.png" and "image2.png" horizontally and saves the result as "output.png".

## License
This program is licensed under the MIT license. See the LICENSE file for details.
