//
//  7-reference.cpp
//  GrammerOfCpp
//
//  Created by Wangjianlong on 2019/4/25.
//  Copyright © 2019 JL.Com. All rights reserved.
//

#include "7-reference.hpp"
#include <iostream>

using namespace std;

//定义枚举
enum Season {
    spring,
    summer,
    fall,
    winter
};

//定义结构体
struct Student {
    int age;
};

////定义全局变量
//int gA = 88;
//
////定义一个函数 返回一个指向 int的引用
//int & changeG()
//{
//    return gA;
//}


void referenceMain() {
    //lea 将地址值 存存储到寄存器。。基本在操作指针
    /*
     leaq   -0x1cc(%rbp), %rax
     leaq   -0x1ac(%rbp), %rcx ||  将地址 -0x1ac(%rbp) 写入rcx中
    
     movl   $0xa, -0x1ac(%rbp) ||  将10 写入到 地址-0x1ac(%rbp):age中 即 ==> age = 10;
     movq   %rcx, -0x1b8(%rbp) ||  将rcx存储的内容：变量age地址 写入 -0x1b8(%rbp):pAge 对应的内存中 ==> int *pAge = &age;
     movq   -0x1b8(%rbp), %rdx ||
     movl   $0x14, (%rdx)      ||  将20 写入到 rdx存储的地址:变量age地址 中 即 ==> *pAge = 20;
     movq   %rcx, -0x1c0(%rbp) ||  将rcx存储的内容：变量age地址 写入 -0x1c0(%rbp):rAge 地址中 ==> int &rAge = age;
     movq   -0x1c0(%rbp), %rcx ||  将rAge的地址值 -0x1c0(%rbp) 写入到rcx中
     movl   $0x1e, (%rcx)      ||  将30 写入到 rcx中 ==> rAge = 30;
     movq   -0x1c0(%rbp), %rcx ||  将rAge的地址值 -0x1c0(%rbp) 写入到rcx中
     movq   %rcx, -0x1c8(%rbp) ||  将rcx的值 写入到内存 -0x1c8(%rbp):p_rAge ==> int *p_rAge = &rAge;
     movq   %rax, -0x1d8(%rbp) ||  ==> Season season;
     movq   -0x1d8(%rbp), %rax ||  ==> Season &rSeason = season;
     movl   $0x3, (%rax)       ||  ==> rSeason = winter;
     
     
     */
    
    //不存在引用的引用
    //int &&rrAge = rAge;
    
    //不存在引用的引用
    //int & *pRage = &rAge;
//    int *p_rAge = &rAge; //相当于 int *p_rAge = &age;
    
    
    int score = 100;
    const int &rScore = score;
    //当常引用指向了不同类型的数据时,会产生临时变量,即引用指向的并不是初始变量
    const double &rScore1 = score;
    score = 99;
    cout << "score = " << score << endl;
    cout << "rScore = " << rScore << endl;
    cout << "rScore1 = " << rScore1 << endl;
    
    int sA = 10;
    int sB = 20;
    cout << "sA = " << sA << endl;
    cout << "sB = "<< sB << endl;
    //表达式被赋值
    (sA = sB) = 30;
    cout << "sA = " << sA << endl;
    
    
    
    
    cout << "====================end=================" << endl;
}
