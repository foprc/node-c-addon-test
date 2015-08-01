#include <node.h>
#include <v8.h>
// #include <iostream>
// #include <stdio.h>

using namespace v8;
using namespace std;

// A utility function to swap two elements
void swap(unsigned int* a,unsigned int* b)
{
    unsigned int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places the pivot element at its
   correct position in sorted array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right of pivot */
unsigned int partition (unsigned int arr[], unsigned int l, unsigned int h)
{
    unsigned int x = arr[h];    // pivot
    unsigned int i = (l - 1);  // Index of smaller element

    for (unsigned int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(unsigned int arr[], unsigned int l, unsigned int h)
{
    if (l < h)
    {
        unsigned int p = partition(arr, l, h); /* Partitioning index */
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}

unsigned int comp(const void* a, const void* b)
{
    unsigned int arg1 = *static_cast<const unsigned int*>(a);
    unsigned int arg2 = *static_cast<const unsigned int*>(b);

    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

void doSort(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    Local<Object> obj = args[0]->ToObject();

    unsigned int objLength = obj->Get(String::NewFromUtf8(isolate, "length"))->ToObject()->Uint32Value();

    unsigned int arr[objLength];
    for(unsigned int i = 0; i < objLength; i++)
    {
        arr[i] = obj->Get(i)->Uint32Value();
    }

    quickSort(arr, 0, objLength - 1);

    for(unsigned int i = 0; i < objLength; i++)
    {
        Handle<Value> x =  Integer::NewFromUnsigned(isolate,arr[i]);
        obj->Set(i,x);
    }

    args.GetReturnValue().Set(obj);
}

void Init(Handle<Object> target) {
  NODE_SET_METHOD(target, "sortC", doSort);
}

NODE_MODULE(addon, Init)
