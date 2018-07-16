/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   ButtonTemplate_png;
    const int            ButtonTemplate_pngSize = 524;

    extern const char*   ChooseYourWeapon_png;
    const int            ChooseYourWeapon_pngSize = 21355;

    extern const char*   Noise_png;
    const int            Noise_pngSize = 839;

    extern const char*   NoiseDown_png;
    const int            NoiseDown_pngSize = 839;

    extern const char*   NoiseOver_png;
    const int            NoiseOver_pngSize = 837;

    extern const char*   Saw_png;
    const int            Saw_pngSize = 901;

    extern const char*   SawDown_png;
    const int            SawDown_pngSize = 907;

    extern const char*   SawOver_png;
    const int            SawOver_pngSize = 907;

    extern const char*   Square_png;
    const int            Square_pngSize = 705;

    extern const char*   SquareDown_png;
    const int            SquareDown_pngSize = 714;

    extern const char*   SquareOver_png;
    const int            SquareOver_pngSize = 712;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 11;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
