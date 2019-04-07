#include <stdio.h>
#include "WoffDecoder.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *font_path = "../noto-sans-tc.woff";
    DecodedResult *result = decode_from_file_wrapped(font_path);
    size_t buf_len = 0;
    switch (result->error) {
        case DecodeError:
        case DataSourceIsEmpty:
        case OutBufferFull:
        case BuffError:
        case DecompressError:
        case InvalidWoffSize:
        case InputBufferIsEmpty:
        case InvalidWoffSignature:
        case InvalidWoffStructure:
        case CreateFileError:
        case OpenFileError:
        case WriteToFileError:
        case ReadFromFileError:
        case InputPathError:
        case OutputPathError:
            destroy_decoded_result(result);
            printf("failed");
            break;
        case None:
            buf_len = result->decoded_data_len;
            destroy_decoded_result(result);
            printf("success");
            break;
    }
}