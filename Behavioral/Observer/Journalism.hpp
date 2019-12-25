#include "IObserver.hpp"
#include "ISubject.hpp"

#include <string_view>
#include <vector>
using std::vector;
using std::string_view;

class Journalist : public ISubject
{
    private:
       // string message;
        std::string_view message;
        vector<IObserver*> observers;

    public:
        Journalist(): message{""}{}
        //void setMessage(const std::string& t_message);
        void setMessage(std::string_view t_message);
        std::string_view getMessage() const;

        virtual void attach(IObserver* t_io) override;
        virtual void detach(IObserver* t_io) override;
        virtual void notify() override;
};


class Newspaper : public IObserver
{
    private:
        Journalist& subject;
        std::string_view m_message; 
        std::string_view m_newspaperName;
        void printMessage();

    public:
        Newspaper(string_view t_name, Journalist& t_journ):
            subject{t_journ},
            m_message{""},
            m_newspaperName{t_name}{}
        virtual void update(const std::string_view& message) override; 
};