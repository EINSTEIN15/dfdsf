/**
 * @file queue.cpp
 * Implementation of the Queue class.
 *
 * @author CS 225 course staff
 * @date Fall 2009
 */

/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
 */
template <class T>
void Queue<T>::enqueue(T const& newItem)
{// T data;
  // outStack.add(newItem);
  // data=outStack.pop();
  inStack.add(newItem);


}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The item that used to be at the front of the Queue.
 */
template <class T>
T Queue<T>::dequeue()
{
  T data;
  data=outStack.peek();
  outStack.remove();
  return data;

}

/**
 * Adds an element to the ordering structure.
 *
 * @see OrderingStructure::add()
 */
template <class T>
void Queue<T>::add(const T& theItem)
{
  this->enqueue(theItem);


}

/**
 * Removes an element from the ordering structure.
 *
 * @see OrderingStructure::remove()
 */
template <class T>
T Queue<T>::remove()
{
  return this->dequeue();
  
}


template <class T>
T Queue<T>::peek()
{T data;
  T data2;
  while(!inStack.isEmpty())
    {
      data=inStack.remove();
      outStack.add(data);
    }
  data=outStack.peek();
  return data;
    
}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
 */
template <class T>
bool Queue<T>::isEmpty() const
{
  
  if(inStack.isEmpty() && outStack.isEmpty())
    {
      return true;
    }
  else
    {

      return false;

    }
}
