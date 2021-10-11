desc: --depth=5 --alloc-fn=g_malloc --alloc-fn=g_realloc --alloc-fn=g_try_malloc --alloc-fn=g_malloc0 --alloc-fn=g_mem_chunk_alloc
cmd: gosdt m2.csv experiments/configurations/debug.json
time_unit: i
#-----------
snapshot=0
#-----------
time=0
mem_heap_B=0
mem_heap_extra_B=0
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=1
#-----------
time=3433500
mem_heap_B=50415216
mem_heap_extra_B=4120
mem_stacks_B=0
heap_tree=peak
n2: 50415216 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n1: 50331648 0x14DD19: Encoder::tokenize(std::istream&, std::vector<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::allocator<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > >&) (in /usr/local/bin/gosdt)
  n1: 50331648 0x15412C: Encoder::Encoder(std::istream&) (in /usr/local/bin/gosdt)
   n1: 50331648 0x15EC67: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
    n1: 50331648 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
     n0: 50331648 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
 n0: 83568 in 31 places, all below massif's threshold (1.00%)
#-----------
snapshot=2
#-----------
time=101462972
mem_heap_B=772424
mem_heap_extra_B=20336
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=3
#-----------
time=196263086
mem_heap_B=1373624
mem_heap_extra_B=40376
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=4
#-----------
time=274684877
mem_heap_B=1844504
mem_heap_extra_B=56072
mem_stacks_B=0
heap_tree=detailed
n6: 1844504 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n2: 1659120 0x142207: Queue::push(Message const&) (in /usr/local/bin/gosdt)
  n2: 1657920 0x13C34B: Task::send_explorer(Task const&, float, int, unsigned int) (in /usr/local/bin/gosdt)
   n1: 828960 0x13DA45: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 828960 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 828960 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
   n1: 828960 0x13DAF6: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 828960 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 828960 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
  n0: 1200 in 2 places, all below massif's threshold (1.00%)
 n1: 72704 0x4A18C19: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
  n1: 72704 0x4011B89: call_init.part.0 (dl-init.c:72)
   n1: 72704 0x4011C90: call_init (dl-init.c:30)
    n1: 72704 0x4011C90: _dl_init (dl-init.c:119)
     n1: 72704 0x4001139: ??? (in /usr/lib/x86_64-linux-gnu/ld-2.31.so)
      n0: 72704 0x2: ???
 n3: 39008 0x1601BE: std::vector<Bitmask, std::allocator<Bitmask> >::_M_fill_insert(__gnu_cxx::__normal_iterator<Bitmask*, std::vector<Bitmask, std::allocator<Bitmask> > >, unsigned long, Bitmask const&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F804: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F821: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
  n0: 544 in 2 places, all below massif's threshold (1.00%)
 n1: 32768 0x1575DD: void std::vector<Bitmask, std::allocator<Bitmask> >::_M_realloc_insert<Bitmask&>(__gnu_cxx::__normal_iterator<Bitmask*, std::vector<Bitmask, std::allocator<Bitmask> > >, Bitmask&) (in /usr/local/bin/gosdt)
  n1: 32768 0x152FE1: Encoder::encode(std::vector<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::allocator<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > > const&, std::vector<Bitmask, std::allocator<Bitmask> >&) const (in /usr/local/bin/gosdt)
   n1: 32768 0x154154: Encoder::Encoder(std::istream&) (in /usr/local/bin/gosdt)
    n1: 32768 0x15EC67: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
     n0: 32768 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
 n0: 21672 in 72 places, all below massif's threshold (1.00%)
 n1: 19232 0x15FCB5: std::vector<Bitmask, std::allocator<Bitmask> >::operator=(std::vector<Bitmask, std::allocator<Bitmask> > const&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F387: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
#-----------
snapshot=5
#-----------
time=340188569
mem_heap_B=2134424
mem_heap_extra_B=65736
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=6
#-----------
time=429358930
mem_heap_B=2635784
mem_heap_extra_B=82448
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=7
#-----------
time=563871203
mem_heap_B=3127784
mem_heap_extra_B=98848
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=8
#-----------
time=653786237
mem_heap_B=3378104
mem_heap_extra_B=107192
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=9
#-----------
time=706410901
mem_heap_B=3477464
mem_heap_extra_B=110504
mem_stacks_B=0
heap_tree=detailed
n4: 3477464 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n2: 3292080 0x142207: Queue::push(Message const&) (in /usr/local/bin/gosdt)
  n2: 3276960 0x13C34B: Task::send_explorer(Task const&, float, int, unsigned int) (in /usr/local/bin/gosdt)
   n1: 1638480 0x13DA45: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 1638480 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 1638480 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
   n1: 1638480 0x13DAF6: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 1638480 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 1638480 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
  n0: 15120 in 2 places, all below massif's threshold (1.00%)
 n0: 73672 in 74 places, all below massif's threshold (1.00%)
 n1: 72704 0x4A18C19: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
  n1: 72704 0x4011B89: call_init.part.0 (dl-init.c:72)
   n1: 72704 0x4011C90: call_init (dl-init.c:30)
    n1: 72704 0x4011C90: _dl_init (dl-init.c:119)
     n1: 72704 0x4001139: ??? (in /usr/lib/x86_64-linux-gnu/ld-2.31.so)
      n0: 72704 0x2: ???
 n1: 39008 0x1601BE: std::vector<Bitmask, std::allocator<Bitmask> >::_M_fill_insert(__gnu_cxx::__normal_iterator<Bitmask*, std::vector<Bitmask, std::allocator<Bitmask> > >, unsigned long, Bitmask const&) (in /usr/local/bin/gosdt)
  n0: 39008 in 4 places, all below massif's threshold (1.00%)
#-----------
snapshot=10
#-----------
time=796271900
mem_heap_B=3714344
mem_heap_extra_B=118400
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=11
#-----------
time=871078531
mem_heap_B=3850424
mem_heap_extra_B=122952
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=12
#-----------
time=990641065
mem_heap_B=4055144
mem_heap_extra_B=129776
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=13
#-----------
time=1046583820
mem_heap_B=4184504
mem_heap_extra_B=134088
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=14
#-----------
time=1136495800
mem_heap_B=4287464
mem_heap_extra_B=137520
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=15
#-----------
time=1270881753
mem_heap_B=4394504
mem_heap_extra_B=141088
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=16
#-----------
time=1349463790
mem_heap_B=4352984
mem_heap_extra_B=139704
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=17
#-----------
time=1482354947
mem_heap_B=4287464
mem_heap_extra_B=137520
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=18
#-----------
time=1564288166
mem_heap_B=4244504
mem_heap_extra_B=136088
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=19
#-----------
time=1646219397
mem_heap_B=4228904
mem_heap_extra_B=135568
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=20
#-----------
time=1769156123
mem_heap_B=4150424
mem_heap_extra_B=132952
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=21
#-----------
time=1871625439
mem_heap_B=4045544
mem_heap_extra_B=129456
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=22
#-----------
time=1933188722
mem_heap_B=3987464
mem_heap_extra_B=127520
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=23
#-----------
time=2056214805
mem_heap_B=3847784
mem_heap_extra_B=122864
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=24
#-----------
time=2138195460
mem_heap_B=3769544
mem_heap_extra_B=120256
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=25
#-----------
time=2240504008
mem_heap_B=3644744
mem_heap_extra_B=116096
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=26
#-----------
time=2343033764
mem_heap_B=3499784
mem_heap_extra_B=111264
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=27
#-----------
time=2424853192
mem_heap_B=3380984
mem_heap_extra_B=107304
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=28
#-----------
time=2520300601
mem_heap_B=3245624
mem_heap_extra_B=102792
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=29
#-----------
time=2587859493
mem_heap_B=3148424
mem_heap_extra_B=99552
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=30
#-----------
time=2655491172
mem_heap_B=3049064
mem_heap_extra_B=96240
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=31
#-----------
time=2723236737
mem_heap_B=2946824
mem_heap_extra_B=92832
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=32
#-----------
time=2791001042
mem_heap_B=2847224
mem_heap_extra_B=89512
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=33
#-----------
time=2858508205
mem_heap_B=2742344
mem_heap_extra_B=86016
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=34
#-----------
time=2926214862
mem_heap_B=2637704
mem_heap_extra_B=82528
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=35
#-----------
time=3027790015
mem_heap_B=2478584
mem_heap_extra_B=77224
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=36
#-----------
time=3129115143
mem_heap_B=2322824
mem_heap_extra_B=72032
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=37
#-----------
time=3230540324
mem_heap_B=2156744
mem_heap_extra_B=66496
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=38
#-----------
time=3331972198
mem_heap_B=1991144
mem_heap_extra_B=60976
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=39
#-----------
time=3399573694
mem_heap_B=1876664
mem_heap_extra_B=57160
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=40
#-----------
time=3467170570
mem_heap_B=1755704
mem_heap_extra_B=53128
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=41
#-----------
time=3534893382
mem_heap_B=1637864
mem_heap_extra_B=49200
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=42
#-----------
time=3602587916
mem_heap_B=1510904
mem_heap_extra_B=44968
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=43
#-----------
time=3704040842
mem_heap_B=1319144
mem_heap_extra_B=38576
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=44
#-----------
time=3805428719
mem_heap_B=1144904
mem_heap_extra_B=32768
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=45
#-----------
time=3872937011
mem_heap_B=1017464
mem_heap_extra_B=28520
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=46
#-----------
time=3974350052
mem_heap_B=813464
mem_heap_extra_B=21704
mem_stacks_B=0
heap_tree=detailed
n6: 813464 (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
 n3: 628080 0x142207: Queue::push(Message const&) (in /usr/local/bin/gosdt)
  n2: 379680 0x162528: Optimizer::signal_exploiters(tbb::interface5::concurrent_hash_map<Tile, tbb::interface5::concurrent_unordered_map<Tile, std::pair<Bitmask, float>, std::hash<Tile>, std::equal_to<Tile>, tbb::scalable_allocator<std::pair<Tile const, std::pair<Bitmask, float> > > >, GraphVertexHashComparator, tbb::scalable_allocator<std::pair<Tile const, tbb::interface5::concurrent_unordered_map<Tile, std::pair<Bitmask, float>, std::hash<Tile>, std::equal_to<Tile>, tbb::scalable_allocator<std::pair<Tile const, std::pair<Bitmask, float> > > > > > >::accessor&, Task&, unsigned int) (in /usr/local/bin/gosdt)
   n1: 379680 0x168FC7: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
    n1: 379680 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
     n0: 379680 0x17BBB5: GOSDT::work(int, Optimizer&, int&) (in /usr/local/bin/gosdt)
   n0: 0 in 1 place, below massif's threshold (1.00%)
  n2: 248400 0x13C34B: Task::send_explorer(Task const&, float, int, unsigned int) (in /usr/local/bin/gosdt)
   n1: 124320 0x13DAF6: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 124320 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 124320 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
   n1: 124080 0x13DA45: Task::send_explorers(float, unsigned int) (in /usr/local/bin/gosdt)
    n1: 124080 0x169012: Optimizer::dispatch(Message const&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 124080 0x16FBB7: Optimizer::iterate(unsigned int) (in /usr/local/bin/gosdt)
  n0: 0 in 1 place, below massif's threshold (1.00%)
 n1: 72704 0x4A18C19: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.28)
  n1: 72704 0x4011B89: call_init.part.0 (dl-init.c:72)
   n1: 72704 0x4011C90: call_init (dl-init.c:30)
    n1: 72704 0x4011C90: _dl_init (dl-init.c:119)
     n1: 72704 0x4001139: ??? (in /usr/lib/x86_64-linux-gnu/ld-2.31.so)
      n0: 72704 0x2: ???
 n3: 39008 0x1601BE: std::vector<Bitmask, std::allocator<Bitmask> >::_M_fill_insert(__gnu_cxx::__normal_iterator<Bitmask*, std::vector<Bitmask, std::allocator<Bitmask> > >, unsigned long, Bitmask const&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F804: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F821: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
  n0: 544 in 2 places, all below massif's threshold (1.00%)
 n1: 32768 0x1575DD: void std::vector<Bitmask, std::allocator<Bitmask> >::_M_realloc_insert<Bitmask&>(__gnu_cxx::__normal_iterator<Bitmask*, std::vector<Bitmask, std::allocator<Bitmask> > >, Bitmask&) (in /usr/local/bin/gosdt)
  n1: 32768 0x152FE1: Encoder::encode(std::vector<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >, std::allocator<std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > > const&, std::vector<Bitmask, std::allocator<Bitmask> >&) const (in /usr/local/bin/gosdt)
   n1: 32768 0x154154: Encoder::Encoder(std::istream&) (in /usr/local/bin/gosdt)
    n1: 32768 0x15EC67: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
     n0: 32768 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
 n0: 21672 in 72 places, all below massif's threshold (1.00%)
 n1: 19232 0x15FCB5: std::vector<Bitmask, std::allocator<Bitmask> >::operator=(std::vector<Bitmask, std::allocator<Bitmask> > const&) (in /usr/local/bin/gosdt)
  n1: 19232 0x15F387: Dataset::construct_bitmasks(std::istream&) (in /usr/local/bin/gosdt)
   n1: 19232 0x15F8CF: Dataset::load(std::istream&) (in /usr/local/bin/gosdt)
    n1: 19232 0x1719AD: State::initialize(std::istream&, unsigned int) (in /usr/local/bin/gosdt)
     n0: 19232 0x17BC55: GOSDT::fit(std::istream&, std::unordered_set<Model, std::hash<Model>, std::equal_to<Model>, std::allocator<Model> >&) (in /usr/local/bin/gosdt)
#-----------
snapshot=47
#-----------
time=4041966743
mem_heap_B=649784
mem_heap_extra_B=16248
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=48
#-----------
time=4109477727
mem_heap_B=441944
mem_heap_extra_B=9320
mem_stacks_B=0
heap_tree=empty
#-----------
snapshot=49
#-----------
time=4176985308
mem_heap_B=212024
mem_heap_extra_B=1656
mem_stacks_B=0
heap_tree=empty
