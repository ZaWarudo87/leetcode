#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,sse4.2,fma,tune=native")
#pragma GCC optimize(                                                          \
    "Ofast,unroll-loops,fast-math,no-stack-protector,tree-vectorize,prefetch-loop-arrays,inline-functions")
#pragma GCC optimize("ipa-cp,ipa-sra,ipa-ra")
#pragma GCC optimize("align-functions,split-loops,split-paths")

static const bool Booster = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();
