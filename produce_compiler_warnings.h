// A "compiler bomb" producing many compiler warning messages, based on an answer of this code challenge:
// https://codegolf.stackexchange.com/questions/5802/write-the-shortest-program-that-generates-the-most-compiler-warnings-and-errors

template <int i>
void bar();
template <int i>
void produce_compiler_warnings()
{
    bar<i>();
    char baz[i];
}
template <>
inline void produce_compiler_warnings<0>()
{}
template <int i>
void bar()
{
    produce_compiler_warnings<i-1>();
}
//template <>
//inline void bar<0>()
//{}
