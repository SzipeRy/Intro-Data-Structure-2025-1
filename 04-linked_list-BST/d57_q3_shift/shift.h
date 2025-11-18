#ifndef __STUDENT_H_
#define __STUDENT_H_

void shift(int k) {
	// TODO: Add your code here
	if (k < 0)
	{
		k--;
		k = abs(k);
	}
	int size = mSize;
	int move = k % size;

	// std::cout << "Move : " << move << '\n';

	auto target = mHeader->next;

	for (int i = 0; i < move; i++)
	{
		target = target->next;
	}
	
	mHeader->prev->next = mHeader->next;
	mHeader->next->prev = mHeader->prev;

	mHeader->next = target;
	mHeader->prev = target->prev;

	target->prev->next = mHeader;
	target->prev = mHeader;

}

#endif