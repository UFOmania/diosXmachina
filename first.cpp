#include <iostream>

int main()
{
    int data[4][3] = {{0,0,0},{1,0,0},{0,1,0}, {1,1,1}};
    float w1 = 0,w2 = 0,n1 = 0,n2 = 0,bias = 0;

    for(int i = 0; i < 10; i++)
    {
        std::cout << "-----" << i << "-----\n";
        for(int j = 0; j < 4; j++)
        {
            n1 = data[j][0];
            n2 = data[j][1];
            float expected = data[j][2];

            float y = (n1 * w1) + (n2 * w2) + bias;
            float res = (y > 0) ? 1 : 0;
            float error = expected - res;
            std::cout << n1 << " " << n2 << " exp " << expected << " got " << res << std::endl; 

            w1 += n1 * error * 0.1f;
            w2 += n2 * error * 0.1f;
            bias += error * 0.1f;
        }
    } 
    std::cout << w1 << " " << w2 << " " << bias<<std::endl;

    for(int i = 0; i < 4; i++)
    {
        std::cout << (((data[i][0]*w1) + (data[i][1]*w2) + bias) > 0)  <<std::endl;
    }
}