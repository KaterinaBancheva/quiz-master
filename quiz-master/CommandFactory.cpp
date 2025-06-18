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
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: like_quiz <id>");
        }
        return new LikeQuizCommand(id);
    }
    else if (cmd == "unlike_quiz")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: unlike_quiz <id>");
        }
        return new UnlikeQuizCommand(id);
    }
    else if (cmd == "add_to_favs")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: add_to_favs <id>");
        }
        return new AddToFavsCommand(id);
    }
    else if (cmd == "remove_from_favs")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: remove_from_favs <id>");
        }
        return new RemoveFromFavsCommand(id);
    }
    else if (cmd == "start_quiz_normal")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: startQuiz_normal <id> <shuffle_on/off>");
        }
        MyString shuffleStr;
        bool shuffle = false;
        if (iss >> shuffleStr)
        {
            if (shuffleStr == "shuffle_on") shuffle = true;
            else if (shuffleStr == "shuffle_off") shuffle = false;
            else throw std::invalid_argument("Usage: start_quiz_normal <id> <shuffle_on/off>");
        }
        else throw std::invalid_argument("Usage: start_quiz_normal <id> <shuffle_on/off>");

        return new StartQuizNormalCommand(id, shuffle);
    }
    else if (cmd == "start_quiz_test")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: startQuiz_test <id> <shuffle_on/off>");
        }
        MyString shuffleStr;
        bool shuffle = false;
        if (iss >> shuffleStr)
        {
            if (shuffleStr == "shuffle_on") shuffle = true;
            else if (shuffleStr == "shuffle_off") shuffle = false;
            else throw std::invalid_argument("Usage: start_quiz_test <id> <shuffle_on/off>");
        }
        else throw std::invalid_argument("Usage: start_quiz_test <id> <shuffle_on/off>");

        return new StartQuizTestCommand(id, shuffle);
    }
    else if (cmd == "save_quiz")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: save_quiz <id> <filepath>");
        }

       /* MyString string;
        std::string str;
        std::getline(iss, str);
        string = str.c_str();
        return new SaveQuizCommand(id, string);*/

        std::string filepath;
        std::getline(iss >> std::ws, filepath);
        return new SaveQuizCommand(id, MyString(filepath.c_str()));
    }
    else if (cmd == "report_quiz")
    {
        unsigned id = 0;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: report_quiz <id> <reason>");
        }
        //std::string str;
        
      /*  char buff[256];
        std::cin.getline(buff, 256);
        std::cout << buff;*/

        std::string reason;
        std::getline(iss >> std::ws, reason);

        return new ReportQuizCommand(id, reason.c_str());
    }
    else if (cmd == "pending")
    {
        return new PendingCommand();
    }
    else if (cmd == "approve_quiz")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: approve_quiz <id>");
        }
        return new ApproveQuizCommand(id);
    }
    else if (cmd == "reject_quiz")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: reject_quiz <id> <reason>");
        }
        std::string str;
        std::getline(iss, str);
        if (!str.empty() && str[0] == ' ')
            str.erase(0, 1);
        return new RejectQuizCommand(id, str.c_str());
    }
    else if (cmd == "view_reports")
    {
        return new ViewReportsCommand();
    }
    else if (cmd == "remove_quiz")
    {
        unsigned id;
        if (!(iss >> id))
        {
            throw std::invalid_argument("Usage: remove_quiz <id> <reason>");
        }
        std::string str;
        std::getline(iss, str);
        if (!str.empty() && str[0] == ' ')
            str.erase(0, 1);
        return new RemoveQuizCommand(id, str.c_str());
    }
    else if (cmd == "ban")
    {
        MyString str;
        iss >> str;
        return new BanCommand(str);
    }
    else 
    {
        throw std::invalid_argument("Unknown command: " + cmd);
    }

    return nullptr;
}
