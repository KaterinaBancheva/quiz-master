#include "CommandFactory.h"
#include <sstream>

Command* CommandFactory::generateCommand(const MyString& fullLine)
{
    std::string lineStr(fullLine.c_str()); 
    std::stringstream iss(lineStr);       

    std::string cmd;
    iss >> cmd;

    if (cmd == "login") 
    {
        std::string username, password;
        iss >> username >> password;
        if (username.empty() || password.empty()) {
            throw std::invalid_argument("Usage: login <username> <password>");
        }
        return new LoginCommand(username.c_str(), password.c_str());
    }
    else if (cmd == "quit")
    {
        return new QuitCommand();
    }
    else if (cmd == "logout")
    {
        return new LogoutCommand();
    }
    else if (cmd == "help")
    {
       // return new HelpCommand();
    }
    else if (cmd == "sign_up")
    {
        std::string username, password, familyName, name, password2;
        iss >> name >> familyName >> username >> password >> password2;
        return new SignUpCommand(name.c_str(), familyName.c_str(), username.c_str(), password.c_str(), password2.c_str());
    }
    else if (cmd == "view_profile")
    {
        return new ViewProfileCommand();
    }
    else if (cmd == "view")
    {
        std::string username;
        iss >> username;
        return new ViewCommand(username.c_str());
    }
    else if (cmd == "view_challenges")
    {
        return new ViewChallengesCommand();
    }
    else if (cmd == "view_finished_challenges")
    {
        return new ViewFinishedChallengesCommand();
    }
    else if (cmd == "messages")
    {
        return new MessagesCommand();
    }
    else if (cmd == "create_quiz")
    {
        return new CreateQuizCommand();
    }
    else if (cmd == "quizzes")
    {
        //two overloads
    }
    else if (cmd == "like_quiz")
    {

    }
    else if (cmd == "unlike_quiz")
    {

    }
    else if (cmd == "add_to_favs")
    {

    }
    else if (cmd == "remove_from_favs")
    {

    }
    else if (cmd == "startQuiz_normal")
    {

    }
    else if (cmd == "startQuiz_test")
    {

    }
    else if (cmd == "save_quiz")
    {

    }
    else if (cmd == "report_quiz")
    {

    }
    else if (cmd == "pending")
    {

    }
    else if (cmd == "approve_quiz")
    {

    }
    else if (cmd == "reject_quiz")
    {

    }
    else if (cmd == "view_repports")
    {

    }
    else if (cmd == "remove_quiz")
    {

    }
    else if (cmd == "ban")
    {

    }
    else 
    {
        throw std::invalid_argument("Unknown command: " + cmd);
    }

    return nullptr;
}
