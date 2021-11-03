#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include "median_filter.h"

template <typename T>
MedianFilter<T>::MedianFilter(int data_num){
  if (data_num < 3)
  {
    data_num = 3;
  }
  _data_num = data_num;
  _is_even = _data_num%2==0? true:false;
  _med = 0.0;
  _head = 0;
  _update_flag = 0;
  _buffer = new T[_data_num];
  memset((void *)_buffer, 0.0, sizeof(T) * _data_num);
  _iter = 0;
}

template <typename T>
void MedianFilter<T>::setDataNum(int data_num) {
  delete[] _buffer;
  _buffer = new T[data_num];
  memset((void *)_buffer, 0.0, sizeof(T) * data_num);
}

template <typename T>
void MedianFilter<T>::input(T input_value) {
  _iter++;
  if (_buffer[_head] < _med)
  {
    if (input_value <= _med)
    {
      // _med not change
      _update_flag = 0;
    }else{
      // find bigger _med value to replace _med
      _update_flag = 2;
    }
  }else if (_buffer[_head] > _med)
  {
    if (input_value >= _med)
    {
      // _med not chage
      _update_flag = 0;
    }else{
      // find smaller _med value to replace _med
      _update_flag = 1;
    }
  }else{
    if (input_value > _med)
    {
      // find bigger _med value to replace _med
      _update_flag = 2;
    }else{
      // find smaller _med value to replace _med
      _update_flag = 1;
    }
  }

  _buffer[_head] = input_value;
  _head++;
  _head %= _data_num;

  if (_update_flag != 0)
  {
    updateMedVaule();
  }

}

template <typename T>
void MedianFilter<T>::updateMedVaule() {
  T med_smaller = std::numeric_limits<T>::min();
  T med_bigger = std::numeric_limits<T>::max();
  int small_cnt = 0;
  int big_cnt = 0;

  for (int i = 0; i < _data_num; ++i)
  {
    if (_buffer[i] < _med)
    {
      small_cnt++;
      if (_buffer[i] > med_smaller)
      {
        med_smaller = _buffer[i];
      }
    }else if (_buffer[i] > _med)
    {
      big_cnt++;
      if (_buffer[i] < med_bigger)
      {
        med_bigger = _buffer[i];
      }
    }else{
      continue;
    }
  }

  if (_update_flag == 1)
  {
    if (small_cnt == _data_num/2+1)
    {
      _med = med_smaller;
    }
  }else{
    if (_is_even)
    {
      big_cnt++;
    }
    if (big_cnt == _data_num/2+1)
    {
      _med = med_bigger;
    }
  }

}

template <typename T>
T MedianFilter<T>::output() {
  return _med;
}

template <typename T>
int MedianFilter<T>::getDataNum(void) {
  return _data_num;
}

template <typename T>
void MedianFilter<T>::clear(void) {
  memset((void *)_buffer, 0.0, sizeof(T) * _data_num);
}

template <typename T>
MedianFilter<T>::~MedianFilter() {
  delete[] _buffer;
}

template class MedianFilter<double>;
template class MedianFilter<float>;