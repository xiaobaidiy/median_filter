#include <median_filter.h>
#include <Config.h>
#include <iostream>
#include <cstdlib>

int main()
{
  #ifdef PRINT_VERSION
  std::cout << "Version " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
  #endif

  MedianFilter<float> mf(5);
  const int N = 50;
  float testValue = 0;
  float dataIn[N];
  float dataOut[N];
  std::cout << "dataIn ";
  for (int i = 0; i < N; ++i)
  {
    dataIn[i] = (float)(rand()%100)/10.;
    mf.input(dataIn[i]);
    dataOut[i] = mf.output();
    std::cout << dataIn[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "dataOut ";
  for (int i = 0; i < N; ++i)
  {
    std::cout << dataOut[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}