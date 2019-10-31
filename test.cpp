#include <iostream>
#include <Eigen/Dense>
#include <Eigen/LU> 
using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;
int main()
{
  MatrixXd m(3,3);
  m(0,0) = 1;
  m(1,0) = -1;
  m(0,1) = -1;
  m(1,1) = 2;
  m(0,2) = 0;
  m(2,0) = 0;
  m(2,2) = 1;
  m(2,1) = -1;
  m(1, 2) = -1;
  std::cout << m << endl << std::endl;
  std::cout << m.inverse() << std::endl;

  VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  cout << v << endl;


  MatrixXd m2(2,2);
  m2(0,0) = 3;
  m2(1,0) = -1;
  m2(0,1) = -1;
  m2(1,1) = 2;
  std::cout << m2 << endl << std::endl;
  std::cout << m2.inverse() << std::endl;
  std:: cout << (m2.inverse()*m2) << std::endl;



}
