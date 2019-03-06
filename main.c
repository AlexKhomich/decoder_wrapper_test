#include <stdio.h>
#include "WoffDecoder.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* font_path = "../noto-sans-tc.woff";
    size_t decoded_len;
    uint8_t *decoded_data;
    decoded_data = decode_from_file_wrapped(font_path, &decoded_len);
}