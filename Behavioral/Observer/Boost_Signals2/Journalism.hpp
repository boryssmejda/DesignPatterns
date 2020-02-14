#include "IObserver.hpp"

#include <iostream>
#include <string_view>
#include <vector>
#include <boost/signals2.hpp>

using std::vector;
using std::string_view;
class Newspaper;

class Journalist
{
    private:
        using UpdateHandler = boost::signals2::signal<void(string_view)>;
        UpdateHandler m_sig;
        std::string_view message;

    public:
        Journalist(): message{""}{}
        void setMessage(std::string_view t_message);
        std::string_view getMessage() const;

        void subscribe(Newspaper& t_newspaper);
        void unsubscribe(Newspaper& t_newspaper);
};


class Newspaper : public IObserver
{
    private:
        std::string_view m_message; 
        std::string_view m_newspaperName;
        void printMessage();

    public:
        Newspaper(string_view t_name):
            m_message{""},
            m_newspaperName{t_name}{}

        virtual void update(const std::string_view& message) override;
};