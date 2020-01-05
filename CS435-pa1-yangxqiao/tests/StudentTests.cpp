#include "catch.hpp"
#include "RleData.h"
#include "RleFile.h"
#include "SrcMain.h"

// Helper function declarations (don't change these)
extern bool BuffersAreSame(const char* expected, const char* actual, size_t size);
extern bool RunCompressionTest(char* test, size_t testSize,
							   char* expected, size_t expectedSize);
extern bool RunDecompressionTest(char* test, size_t testSize,
								 char* expected, size_t expectedSize);
extern bool CheckFileMD5(const std::string& fileName, const std::string& expected);

TEST_CASE("RLE Compression", "[student]")
{
    SECTION("Basic positive run")
    {
        char test[] = "aaabbbcccdddaaabbbcccdddaaabbbcccdddaaabbbc"
        "ccdddaaabbbcccdddaaabbbcccdddaaabbbcccdddaaabbbcccddd";
        char expected[] = "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d"
        "\x03" "a" "\x03" "b" "\x03" "c" "\x03" "d";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Advanced positive run")
    {
        char test[] = "aaaaaaaaaabbbbbbbbccccccddddddddddddddeeeeeeeeeeeeeeeeee"
        "fffffffffffffffffzzzzzzzzzzzzzzzzzzzzzzzzzzzaaaa"
        "ggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
        "abbbccccggggglllllllliiiiiiimmmnn";
        char expected[] = "\x0a" "a" "\x08" "b" "\x06" "c" "\x0e" "d" "\x12" "e"
        "\x11" "f" "\x1b" "z" "\x04" "a" "\x19" "g" "\x20" "h" "\x01" "a" "\x03"
        "b" "\x04" "c" "\x05" "g" "\x08" "l" "\x07" "i" "\x03" "m" "\x02" "n";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Basic negative run")
    {
        char test[] = "abcdefghijklmnopqrstuvwxvzabcdefghijklmnopqrstuvwxvz"
        "abcdefghijklmnopqrstuvwxvzabcdefghijklmnopqrstuvwxvz";
        char expected[] = "\x98" "abcdefghijklmnopqrstuvwxvzabcdefghijklmn"
        "opqrstuvwxvzabcdefghijklmnopqrstuvwxvzabcdefghijklmnopqrstuvwxvz";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }


    SECTION("Basic positive and negative run")
    {
        char test[] = "aaaaaaabcde8888888wxvizhbbbbbb1sakznzwdnsniszhhhhhhhhh"
        "nauinjasnioewhuinonjksjjjjjjjjjjjjjjjjjjjj";
        char expected[] = "\x07" "a" "\xfc" "bcde" "\x07" "8" "\xfa" "wxvizh"
        "\x06" "b" "\xf1" "1sakznzwdnsnisz" "\x09" "h" "\xea" "nauinjasnioewhuinonjks"
        "\x14" "j";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Advanced positive and negative run")
    {
        char test[] = "abcdefghijklmnopqrstuvwxvzBBBabcdefghijklmnopqrstuvwxvz"
        "BBBabcdefghijklmnopqrstuvwxvzBBBabcdefghijklmnopqrstuvwxvz";
        char expected[] = "\xe6" "abcdefghijklmnopqrstuvwxvz" "\x03" "B"
        "\xe6" "abcdefghijklmnopqrstuvwxvz" "\x03" "B"
        "\xe6" "abcdefghijklmnopqrstuvwxvz" "\x03" "B"
        "\xe6" "abcdefghijklmnopqrstuvwxvz";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Basic 128 positive run")
    {
        char test[] = "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaa";
        char expected[] = "\x7f" "a" "\x01" "a";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Advanced 256 positive run")
    {
        char test[] = "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaa"
        ;
        char expected[] = "\x7f" "a" "\x7f" "a" "\x02" "a";

        bool result = RunCompressionTest(test, sizeof(test) - 1,
                                         expected, sizeof(expected) - 1);
        REQUIRE(result);
    }
}

TEST_CASE("RLE Decompression", "[student]")
{
    SECTION("Basic positive run")
    {
        char test[] = "\x28" "x";
        char expected[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

        bool result = RunDecompressionTest(test, sizeof(test) - 1,
                                           expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Basic negative run")
    {
        char test[] = "\xf5" "abcdefghijk";
        char expected[] = "abcdefghijk";

        bool result = RunDecompressionTest(test, sizeof(test) - 1,
                                           expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Basic negative and positive run")
    {
        char test[] = "\x06" "c" "\xf5" "abcdefghijk" "\x08" "b";
        char expected[] = "ccccccabcdefghijkbbbbbbbb";

        bool result = RunDecompressionTest(test, sizeof(test) - 1,
                                           expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

    SECTION("Advanced negative and positive run")
    {
        char test[] = "\x7f" "a" "\xf5" "abcdefghijk";
        char expected[] = "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaabcdefghijk";

        bool result = RunDecompressionTest(test, sizeof(test) - 1,
                                           expected, sizeof(expected) - 1);
        REQUIRE(result);
    }

}

TEST_CASE("Command line arguments", "[student]")
{
    SECTION("instructions.txt.rl1")
    {
        const char* argv[] = {
            "tests/tests",
            "data/instructions.txt.rl1"
        };
        ProcessCommandArgs(2, argv);
        bool result = CheckFileMD5("data/instructions.txt", "5e042d2e4bf014e714dd7cfc4dc25aab");
        REQUIRE(result);
    }
}

TEST_CASE("File compression", "[student]")
{
    RleFile r;
    SECTION("rle.bmp")
    {
        r.CreateArchive("data/rle.bmp");
        bool result = CheckFileMD5("data/rle.bmp.rl1", "f2a9d8425d53c664e45d9eb1b53137b9");
        REQUIRE(result);
    }
    SECTION("pic.jpg")
    {
        r.CreateArchive("data/pic.jpg");
        bool result = CheckFileMD5("data/pic.jpg.rl1", "0bbf2a5109b30d79939d2061ea8c74aa");
        REQUIRE(result);
    }
    SECTION("Conquest.ogg")
    {
        r.CreateArchive("data/Conquest.ogg");
        bool result = CheckFileMD5("data/Conquest.ogg.rl1", "ec29ff368ec5100bfba22635ddc5ba5c");
        REQUIRE(result);
    }
}

TEST_CASE("File decompression", "[student]")
{
    RleFile r;
    SECTION("works.bmp.rl1")
    {
        r.ExtractArchive("data/works.bmp.rl1");
        bool result = CheckFileMD5("data/works.bmp", "8baad647acefae2f8c36ee111582a875");
        REQUIRE(result);
    }
    SECTION("xkcd.bmp.rl1")
    {
        r.ExtractArchive("data/xkcd.bmp.rl1");
        bool result = CheckFileMD5("data/xkcd.bmp", "a4d7efa89d47a94a76f8050dd8d60cd0");
        REQUIRE(result);
    }
    SECTION("logo.png.rl1")
    {
        r.ExtractArchive("data/logo.png.rl1");
        bool result = CheckFileMD5("data/logo.png", "95403309460632f60efa647ef59b78fc");
        REQUIRE(result);
    }
}

