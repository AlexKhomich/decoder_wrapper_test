#include <stdio.h>
#include "WoffDecoder.h"
#include "string.h"

inline static const char* to_string(Error err) {
    switch (err) {
        case None: return "None";
        case DecodeError: return "DecodeError";
        case DataSourceIsEmpty: return "DataSourceIsEmpty";
        case OutBufferFull: return "OutBufferFull";
        case BuffError: return "BuffError";
        case DecompressError: return "DecompressError";
        case InvalidWoffSize: return "InvalidWoffSize";
        case InputBufferIsEmpty: return "InputBufferIsEmpty";
        case InvalidWoffSignature: return "InvalidWoffSignature";
        case InvalidWoffStructure: return "InvalidWoffStructure";
        case CreateFileError: return "CreateFileError";
        case OpenFileError: return "OpenFileError";
        case WriteToFileError: return "WriteToFileError" ;
        case ReadFromFileError: return "ReadFromFileError";
        case InputPathError: return "InputPathError";
        case OutputPathError: return "OutputPathError";
        default: return "Undefined";
    }
}

void decode_to_file() {
    const char* font_path = "../noto-sans-tc.ttf";
    const char* out_font_path = "../noto-sans-tc.ttf";
    FileRWResult* result = decode_file_to_file_wrapped(font_path, out_font_path);
    size_t buf_len;
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
            printf("Failed with %s\n", to_string(result->error));
            destroy_file_rw_result(result);
            break;
        case None:
            buf_len = result->data_len;
            destroy_file_rw_result(result);
            printf("File created successfully! Out data length is: %zu\n", buf_len);
            break;
    }
}

void decode_to_buf() {
    const char* font_path = "../noto-sans-tc.woff";
    DecodedResult* result = decode_from_file_wrapped(font_path);
    size_t buf_len;
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
            printf("Failed with %s\n", to_string(result->error));
            destroy_decoded_result(result);
            break;
        case None:
            buf_len = result->decoded_data_len;
            destroy_decoded_result(result);
            printf("Buffer created successfully! Out data length is: %zu\n", buf_len);
            break;
    }
}

int main() {
    decode_to_buf();
    decode_to_file();
    return 0;
}