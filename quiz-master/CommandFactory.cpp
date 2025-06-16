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
       return new HelpCommand();
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
        MyString username;
        iss >> username;
        if (username.getSize() == 0)
        {
            return new QuizzesCommand();
        }
        else
        {
            return new QuizzesCommand(username);
        }
    }
    else if (cmd == "like_quiz")
    {
        unsigned id;
        std::cin >> id;
        return new LikeQuizCommand(id);
    }
    else if (cmd == "unlike_quiz")
    {
        unsigned id;
        std::cin >> id;
        return new UnlikeQuizCommand(id);
    }
    else if (cmd == "add_to_favs")
    {
        unsigned id;
        std::cin >> id;
        return new AddToFavsCommand(id);
    }
    else if (cmd == "remove_from_favs")
    {
        unsigned id;
        std::cin >> id;
        return new RemoveFromFavsCommand(id);
    }
    else if (cmd == "startQuiz_normal")
    {
        unsigned id;
        std::cin >> id;
        bool shuffle;
        std::cin >> shuffle;
        return new StartQuizNormalCommand(id, shuffle);
    }
    else if (cmd == "startQuiz_test")
    {
        unsigned id;
        std::cin >> id;
        bool shuffle;
        std::cin >> shuffle;
        return new StartQuizTestCommand(id, shuffle);
    }
    else if (cmd == "save_quiz")
    {
        unsigned id;
        std::cin >> id;
        MyString str;
        std::cin >> str;
        return new SaveQuizCommand(id, str);
    }
    else if (cmd == "report_quiz")
    {
        unsigned id;
        std::cin >> id;
        MyString str;
        std::cin >> str;
        return new ReportQuizCommand(id, str);
    }
    else if (cmd == "pending")
    {
        return new PendingCommand();
    }
    else if (cmd == "approve_quiz")
    {
        unsigned id;
        std::cin >> id;
        return new ApproveQuizCommand(id);
    }
    else if (cmd == "reject_quiz")
    {
        unsigned id;
        std::cin >> id;
        MyString str;
        std::cin >> str;
        return new RejectQuizCommand(id, str);
    }
    else if (cmd == "view_reports")
    {
        return new ViewReportsCommand();
    }
    else if (cmd == "remove_quiz")
    {
        unsigned id;
        std::cin >> id;
        MyString str;
        std::cin >> str;
        return new RemoveQuizCommand(id, str);
    }
    else if (cmd == "ban")
    {
        MyString str;
        std::cin >> str;
        return new BanCommand(str);
    }
    else 
    {
        throw std::invalid_argument("Unknown command: " + cmd);
    }

    return nullptr;
}
