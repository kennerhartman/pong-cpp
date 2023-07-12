//
// Copyright (c) 2023 by Kenner Hartman. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for details.
//

#include <iostream>


// raylib API
#include "../include/raylib/raylib.h"

int main() {
    std::string resources_path = "resources/";
    std::string str_image_file_name;
    std::string str_image_file_path;

    std::cout << "Name of image file (ensure it's in PNG format and in /resources): ";
    std::cin >> str_image_file_name;
    
    str_image_file_path = resources_path + str_image_file_name + ".png";

    const char* char_image_file_name;
    char_image_file_name = str_image_file_path.c_str();
    
    Image image = LoadImage(char_image_file_name);

    std::string output_file_location = "resources/textures_binary/";
    std::string output_file;
    std::string output_file_path;

    std::cout << "\nName of output file: ";
    std::cin >> output_file;

    output_file_path = output_file_location + output_file + ".hpp";

    const char* char_output_file = output_file_path.c_str();
    ExportImageAsCode(image, char_output_file);

    return 0;
}