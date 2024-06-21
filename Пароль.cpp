#include <iostream>
#include <string>
#include <cctype>

class Password {
private:
    std::string password;

public:
    Password(const std::string& pw) : password(pw) {}

    // Получим пароль
    std::string getPassword() const {
        return password;
    }

    // Установим пароль
    void setPassword(const std::string& newPw) {
        password = newPw;
    }

    // Определение степени безопасности пароля
    std::string getSecurityLevel() const {
        bool hasUppercase = false, hasLowercase = false, hasDigit = false, hasSpecialChar = false;
        for (char c : password) {
            if (isupper(c))
                hasUppercase = true;
            else if (islower(c))
                hasLowercase = true;
            else if (isdigit(c))
                hasDigit = true;
            else if (!isalnum(c))
                hasSpecialChar = true;
        }

        if (hasUppercase && hasLowercase && hasDigit && hasSpecialChar && password.length() >= 8)
            return "Высокая защита";
        else if ((hasUppercase && hasLowercase && hasDigit) || (hasUppercase && hasLowercase && hasSpecialChar) || (hasUppercase && hasDigit && hasSpecialChar) || (hasLowercase && hasDigit && hasSpecialChar))
            return "Средняя защищенность";
        else
            return "Слабая защищенность";
    }

    // Перегрузка операторов сравнения
    bool operator==(const Password& other) const {
        return password == other.password;
    }

    bool operator!=(const Password& other) const {
        return password != other.password;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
        
    Password pw1("Abc123!@#");
    Password pw2("password123");

    std::cout << "Уровень безопасности для '" << pw1.getPassword() << "': " << pw1.getSecurityLevel() << std::endl;
    std::cout << "Уровень безопасности для '" << pw2.getPassword() << "': " << pw2.getSecurityLevel() << std::endl;

    if (pw1 == pw2)
        std::cout << "Пароли одинаковые" << std::endl;
    else
        std::cout << "Пароли разные" << std::endl;

    return 0;
}
