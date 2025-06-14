#include "Message.h"
#include <ctime>
#include <cstring>


using std::ctime;
using std::strncpy;

Message::Message() : timestamp(std::time(nullptr))
{
    sender = MyString();
    content = MyString();
}

Message::Message(const MyString& content, const MyString& sender, const MyString& receiver)
    :sender(sender), timestamp(std::time(nullptr)), content(content), receiver(receiver) {}


void Message::printMessage() const
{
    const char* timeStr = ctime(&timestamp); 
    if (timeStr)
    {
        char timePart[9];
        strncpy(timePart, timeStr + 11, 8); // HH:MM:SS is at position 11–18
        timePart[8] = '\0';

        std::cout << timePart << ", sent by " << sender << ": " << content << std::endl;
    }
    else
    {
        std::cout << "Invalid time, sent by " << sender << ": " << content << std::endl;
    }

}

const MyString& Message::getReceiver() const
{
    return receiver;
}

const MyString& Message::getContent() const
{
    return content;
}

void Message::saveToBinaryFile(std::ofstream& ofs) const
{
    sender.write(ofs);
    receiver.write(ofs);
    ofs.write((const char*)&timestamp, sizeof(timestamp));
    content.write(ofs);
}

void Message::readFromBinaryFile(std::ifstream& ifs)
{
    sender.read(ifs);
    receiver.read(ifs);
    ifs.read((char*)&timestamp, sizeof(timestamp));
    content.read(ifs);
}