#include <array>
#include <fstream>
#include <iostream>
#include <string_view>
#include <variant>

#include"./ppm_lib.hpp"
using namespace ppm;

int main(int argc, char const *argv[]) {
  constexpr int32_t HEIGHT{300};
  constexpr int32_t WIDTH{300};
  const auto file_path = "example1.ppm";
  auto pixels = std::array<uint32_t, HEIGHT * WIDTH>({});
  pixels.fill(0x00FF0000);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/2, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/3, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/4, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/5, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/6, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/7, 0x000000FF, WIDTH, HEIGHT);
  draw_cirlce<uint32_t>(pixels, WIDTH/2, HEIGHT/2, WIDTH/8, 0x000000FF, WIDTH, HEIGHT);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, WIDTH-(WIDTH/2), HEIGHT-(HEIGHT/2), 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/3, HEIGHT/3, WIDTH-(WIDTH/3), HEIGHT-(HEIGHT/3), 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/4, HEIGHT/4, WIDTH-(WIDTH/4), HEIGHT-(HEIGHT/4), 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/5, HEIGHT/5, WIDTH-(WIDTH/5), HEIGHT-(HEIGHT/5), 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/6, HEIGHT/6, WIDTH-(WIDTH/6), HEIGHT-(HEIGHT/6), 0x0000FF00);
  draw_rect<uint32_t>(pixels, WIDTH, HEIGHT, WIDTH/7, HEIGHT/7, WIDTH-(WIDTH/7), HEIGHT-(HEIGHT/7), 0x0000FF00);

  save_as_ppm<uint32_t>(pixels, file_path, (float)WIDTH, HEIGHT);
  return 0;
}
