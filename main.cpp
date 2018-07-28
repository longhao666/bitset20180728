#include <iostream>
#include <bitset>

using namespace std;

/**
bitset的相关函数
对于一个叫做foo的bitset：
foo.size() 返回大小（位数）
foo.count() 返回1的个数
foo.any() 返回是否有1
foo.none() 返回是否没有1
foo.set() 全都变成1
foo.set(p) 将第p + 1位变成1
foo.set(p, x) 将第p + 1位变成x
foo.reset() 全都变成0
foo.reset(p) 将第p + 1位变成0
foo.flip() 全都取反
foo.flip(p) 将第p + 1位取反
foo.to_ulong() 返回它转换为unsigned long的结果，如果超出范围则报错
foo.to_ullong() 返回它转换为unsigned long long的结果，如果超出范围则报错
foo.to_string() 返回它转换为string的结果
 */

/**
初始化bitset对象的方法

bitset<n> b;

b有n位，每位都为0

bitset<n> b(u);

b是unsigned long型u的一个副本

bitset<n> b(s);

b是string对象s中含有的位串的副本

bitset<n> b(s, pos, n);

b是s中从位置pos开始的n个位的副本


b.any()

b中是否存在置为1的二进制位？

b.none()

b中不存在置为1的二进制位吗？

b.count()

b中置为1的二进制位的个数

b.size()

b中二进制位的个数

b[pos]

访问b中在pos处的二进制位

b.test(pos)

b中在pos处的二进制位是否为1？

b.set()

把b中所有二进制位都置为1

b.set(pos)

把b中在pos处的二进制位置为1

b.reset()

把b中所有二进制位都置为0

b.reset(pos)

把b中在pos处的二进制位置为0

b.flip()

把b中所有二进制位逐位取反

b.flip(pos)

把b中在pos处的二进制位取反

b.to_ulong()

用b中同样的二进制位返回一个unsigned long值

os << b

把b中的位集输出到os流
 */

void f1() {
    std::bitset<4> foo (std::string("1001"));
    std::bitset<4> bar (std::string("0011"));
    // 按位异或，相同位不同位1，相同位0
    std::cout << (foo^=bar) << '\n';       // 1010 (XOR,assign)
    // 按位与
    std::cout << (foo&=bar) << '\n';       // 0010 (AND,assign)
    // 按位或
    std::cout << (foo|=bar) << '\n';       // 0011 (OR,assign)
    // 按位左移
    std::cout << (foo<<=2) << '\n';        // 1100 (SHL,assign)
    // 按位右移
    std::cout << (foo>>=1) << '\n';        // 0110 (SHR,assign)
    // 按位取反 ！是非
    std::cout << (~bar) << '\n';           // 1100 (NOT)

    std::cout << (bar<<1) << '\n';         // 0110 (SHL)
    std::cout << (bar>>1) << '\n';         // 0001 (SHR)

    std::cout << (foo==bar) << '\n';       // false (0110==0011)
    std::cout << (foo!=bar) << '\n';       // true  (0110!=0011)

    std::cout << (foo&bar) << '\n';        // 0010
    std::cout << (foo|bar) << '\n';        // 0111
    std::cout << (foo^bar) << '\n';        // 0101
}

void f2() {
    std::bitset<16> foo;
    std::bitset<16> bar (0xfa2);
    std::bitset<16> baz (std::string("0101111001"));

    std::cout << "foo: " << foo << '\n';
    std::cout << "bar: " << bar << '\n';
    std::cout << "baz: " << baz << '\n';
}

int main()
{
    cout << "Hello World!" << endl;

    cout << sizeof(long int) << endl;

    cout << sizeof(unsigned) << endl;

    cout << sizeof(int) << endl;

    cout << sizeof(unsigned int) << endl;

    bitset<8> b(0x07);

    cout << b.to_string() << endl;

    std::cout << b.test(0) << std::endl;
    std::cout << b.test(1) << std::endl;


    std::cout << "================" << '\n';
    f1();
    std::cout << "================" << '\n';
    f2();



    return 0;
}
