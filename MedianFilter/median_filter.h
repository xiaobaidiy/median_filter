#ifndef FILTERS_
#define FILTERS_

template <typename T>
class MedianFilter {
 public:
  MedianFilter(int data_num);
  ~MedianFilter();
  void input(T input_value);
  void setDataNum(int data_num);
  int getDataNum(void);
  T output(void);
  void clear(void);
  void updateMedVaule(void);

 private:
  T *_buffer;
  int _data_num;
  T _med;
  int _head;
  int _update_flag;
  bool _is_even;
  bool _is_first_run;
};
#endif