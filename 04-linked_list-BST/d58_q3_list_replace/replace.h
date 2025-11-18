void replace(const T& x, list<T>& y) {
  //write your code here
  auto it = begin();

  while(it != end())
  {
    if (*it == x)
    {
      for (auto &tmp : y)
      {
        insert(it, tmp);
      }
      it = erase(it);
      continue;
    }

    ++it;
  }

}
