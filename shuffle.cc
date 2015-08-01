#include <node.h>
#include <v8.h>
#include <iostream>
#include <stdio.h>

using namespace v8;
using namespace std;

void shuffle(const FunctionCallbackInfo<Value>& args)
{
    //n min max
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);

    int n = args[0]->ToInteger()->Uint32Value();
    // unsigned int min = args[1]->ToInteger()->Uint32Value();
    // unsigned int max = args[2]->ToInteger()->Uint32Value();
    unsigned int min = 1;
    unsigned int max = n;

    unsigned int arr[n];
    Handle<Array> arr2 = Array::New(isolate, n);
    unsigned int arr2NowSize = n;

    // for (unsigned int i = 0; i < sizeof(arr); i++)
    // {
    //     arr[i] = i + min;
    // }
    //
    // cout << (int) arr[0] << endl;

    for (unsigned int i = 0; i < sizeof(arr); i++)
    {
        int index = rand() % max + min;
        // cout << arr[i] << endl;
        arr2->Set(i, Integer::NewFromUnsigned(isolate, index));
        // for (unsigned int k = 0; k < sizeof(arr); k++ )
        // {
        //     arr[k] = arr[k + 1];
        // }
        // arr2NowSize--;
    }

    args.GetReturnValue().Set(arr2);
}

void Init(Handle<Object> target) {
  NODE_SET_METHOD(target, "genData", shuffle);
}

NODE_MODULE(addon, Init)
