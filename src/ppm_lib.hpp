#ifndef _LIB_PPM_HPP
#define _LIB_PPM_HPP

#include <fstream>
#include <span>

namespace ppm {
/**
 * @brief Saves the provided pixels in a file, this function terminates 
 * the program in case of errors
 * 
 * @param pixs Array of pixels
 * @param file_path Path of the file
 * @param width Width of image 
 * @param height Height  of image
 */
template <typename T>
void save_as_ppm(const std::span<T> pixs, const std::string_view file_path,
                 const size_t width, const size_t height) {

  auto file = std::ofstream(file_path.data(), std::ios::binary);
  if (!(file.is_open())) {
    std::cerr<<"ERROR: failed to open file"<<file_path<<'\n';
    exit(-1);
  }
  file << "P6\n" << width << ' ' << height << "\n255\n";

  for (size_t y = 0; y < height; ++y){
    for (size_t x = 0; x < width; ++x){
        auto pixel = pixs[y * width + x];
        u_char color[3] =  {(u_char)((pixel >> 8 * 2) & 0xFF),
                            (u_char)((pixel >> 8 * 1) & 0xFF),
                            (u_char)((pixel >> 8 * 0) & 0xFF)};
      file.write((char *)color, sizeof(color));
    }
  }
}
/**
 * @brief Draws a rectangle in the bounds of the image, this function terminates 
 * the program in case of errors
 * @param pixs Array of pixels
 * @param width Width of image
 * @param height Heigh of image
 * @param x1 X coordinate of the top left corner
 * @param y1 Y coordinate of the top left corner
 * @param x2 X coordinate of the bottom right corner
 * @param y2 Y coordinate of the bottom right corner
 * @param color Color of the pixel in format 0x00RRGGBB first byte is ignored
 */
template <typename T>
void draw_rect(std::span<T> pixs, const size_t width, const size_t height,
               const size_t x1, const size_t y1, const size_t x2,
               const size_t y2, const uint32_t color) {

  if (x1 > width || x2 > width || y1 > height || y2 > height) {
    std::cerr << " ERROR: Rectangle out of bounds\n";
  }
  for (size_t y = 0; y < height; ++y) {
    for (size_t x = 0; x < width; ++x) {
        if (!(x > x2 || x < x1) && (y == y1 || y == y2)) {
            pixs[y * width + x] = color;
        }else if ((x == x1 || x == x2) && !(y < y1 || y > y2)) {
            pixs[y * width + x] = color;
        }
    }
  }
}
/**
 * @brief Draws a Circle in the bounds of the image, this function terminates 
 * the program in case of errors
 * 
 * @param pixs Array of pixels
 * @param center_x X coordinate of the center
 * @param center_y Y coordinate of the center
 * @param radius 
 * @param color Color of the pixel in format 0x00RRGGBB first byte is ignored
 * @param width Width of image
 * @param height Heigh of image
 */
template <typename T>
void draw_cirlce(std::span<T> pixs, const size_t center_x,
                 const size_t center_y, const float radius,
                 const uint32_t color, const size_t width,
                 const size_t height) {
    if( (center_x + radius > width) || (center_x - radius < 0 || (center_y + radius > height) || (center_x - radius < 0))){
        std::cerr<<"ERROR: Circle drawn out of the image\n";
        exit(-1);
    }
    int rad2 = radius * radius;
    for (size_t y = 0; y < height; ++y) {
    for (size_t x = 0; x < width; ++x) {
        int diff_x = x - center_x;
        int diff_y = y - center_y;
        if (diff_x * diff_x + diff_y * diff_y < rad2 &&
            diff_x * diff_x + diff_y * diff_y >= (radius - 1) * (radius - 1)) 
        {
            pixs[y * width + x] = color;
        }
    }
  }
}
}
#endif