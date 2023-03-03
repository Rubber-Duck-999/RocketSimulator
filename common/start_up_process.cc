#include "start_up_process.h"

static void RunProcess(const std::string program_name)
{
    char message_send[program_name.length() + 1];
    strcpy(message_send, program_name.c_str());
    char* message_ptr_ = message_send;
    FILE *handle = popen(message_ptr_, "r");

    if (handle == NULL) 
    {
        std::cout << "File doesn't exist";
        return;
    }

    char buf[64];
    size_t readn;
    while ((readn = fread(buf, 1, sizeof(buf), handle)) > 0) 
    {
        fwrite(buf, 1, readn, stdout);
    }

    pclose(handle);

    return;
}