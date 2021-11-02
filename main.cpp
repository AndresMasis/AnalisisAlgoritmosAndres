# include "my_header.h"

int main() {
    vector<short> x{7, 16, 41, 52};
    vector<short> u = dynamic_programming(x);
    for (short n : u)
        cout<<n<<endl;

    return 0;
}
