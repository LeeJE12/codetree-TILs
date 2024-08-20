#include <iostream>
#include <string>

using namespace std;

// Spy 정보를 나타내는 클래스 선언
class Spy {
    public:
        string secret_code;
        char meeting_point;
        int time;
        Spy(string secret_code, char meeting_point, int time) {
            this->secret_code = secret_code;
            this->meeting_point = meeting_point;
            this->time = time;
        }
};

int main(){
    // 변수 선언 및 입력
    string s_code;
    char m_point;
    int time;
    cin >> s_code >> m_point >> time;
    
    // Spy 객체를 만들어 줍니다.
    Spy s = Spy(s_code, m_point, time);

    // 결과를 출력합니다.
    cout << "secret code : " << s.secret_code << endl;
    cout << "meeting point : " << s.meeting_point << endl;
    cout << "time : " << s.time << endl;
    return 0;
}