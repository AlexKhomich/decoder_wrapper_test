#include <stdio.h>
#include "WoffDecoder.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *font_path = "../noto-sans-tc.woff";
    Result *result = decode_from_file_wrapped(font_path);
    if (result->error == DecodeError) {
        destroy_buffer(result);
    }
    size_t buf_len = result->decoded_data_len;
    destroy_buffer(result);
}