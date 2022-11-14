#include <iostream>

class IBaseComponent
{
public:
    IBaseComponent(std::string p_name): m_name{p_name}{};
    ~IBaseComponent()= default;
    std::string GetName(){return m_name;};
    bool IsBusy(){return m_busy;};
    
 private:   
    bool m_busy{false};
    std::string m_name{"NULL"};
};