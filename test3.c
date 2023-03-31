#include <stdio.h>
#include <windows.h>

int main() {
    WIN32_FIND_DATA file_data;
    HANDLE file_handle;

    const char* directory_path = "C:\\Users\\Nikita PC\\Desktop\\SB ND"; // замените на свой путь
    file_handle = FindFirstFile(directory_path, &file_data);

    if (file_handle == INVALID_HANDLE_VALUE) {
        printf("Error open catalog: %d\n", GetLastError());
        return 1;
    }

    do {
        printf("File name: %s\n", file_data.cFileName);
        printf("File atribute: %d\n", file_data.dwFileAttributes);
    } while (FindNextFile(file_handle, &file_data) != 0);

    FindClose(file_handle);

    return 0;
}
