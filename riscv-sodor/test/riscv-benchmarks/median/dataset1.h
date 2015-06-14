
#define DATA_SIZE 400

int input_data[DATA_SIZE] =
{
   41, 454, 833, 335, 564,   1, 187, 989, 749, 365, 350, 572, 132,  64, 949, 153, 584, 216, 805, 140,
  621, 210,   6, 572, 931, 339, 890, 593, 392, 898, 694, 228, 961,  12, 110, 883, 116, 750, 296, 646,
  426, 500, 314, 436, 659, 701, 774, 812, 319, 981, 678, 150, 875, 696, 376, 564, 474, 272, 938, 258,
  539, 647, 569, 509, 203,  88, 280, 703, 759, 669, 606, 375, 511, 551, 657, 936, 195, 592,  81, 569,
  267, 952, 229, 800, 337, 584, 944, 643, 902, 368, 241, 489, 913, 328, 826, 313, 933, 592, 985, 388,
  195, 543, 960, 649, 566, 979, 350, 997, 649, 814, 657,  79, 181, 208, 111, 998, 859, 629,  65, 847,
  288, 704, 349, 997, 141, 253, 905, 715, 886, 430, 264, 415, 576, 538, 979, 700, 761,   4, 241, 494,
  478, 100, 499, 864, 403, 693, 222, 416, 444, 296, 721, 285, 676, 620, 317,  78, 224, 351, 937, 540,
  288, 646, 119, 169, 615, 527, 606, 289, 389, 796, 351, 801, 455, 720, 278, 758, 367, 745, 358,  92,
  584, 989,  62, 271, 985, 853, 403, 788, 346, 531, 517, 222, 559, 461, 908, 241, 775, 358, 255, 332,
  778, 684, 598, 740, 143, 446,  33, 311, 125, 743, 941, 557, 933, 479, 799, 557, 553, 925, 431, 796,
  648, 357, 952, 891, 287, 666,  19, 514,  49, 557,  86, 870,  95, 853, 441, 440, 587,  61, 614, 678,
  382, 396, 280,   9, 808,  17, 971, 170, 819, 291, 344, 380, 450, 536, 512, 185, 965, 917, 347, 539,
  808, 983, 882, 887, 537,  54, 946, 612, 701, 951, 356, 479, 567, 151, 891,   7,  22, 641, 568, 335,
  665, 730, 423,  95, 434, 728, 158, 280,   2, 395,  84, 688, 247, 911,  49, 476, 435, 815, 792, 729,
  869, 265, 486, 127, 414, 236, 369, 214, 548, 180, 518,   6, 888, 503, 682, 596, 284, 173, 264, 643,
  499, 346, 290, 599, 897,  68, 215, 849, 731, 658, 688, 619, 251, 121, 786, 131, 555, 828, 302, 667,
  528, 433, 544, 487, 322, 753, 947, 125, 287, 626, 824,  14, 304,  10, 788, 403, 733, 106, 959, 703,
  366, 818, 722, 964, 294, 406, 975, 874, 653, 856, 748,  86,  91,  60, 378, 660, 105, 667, 102, 153,
  381, 121, 651,  98, 825, 412, 840, 236, 356,  12, 148, 423,  54, 965, 140, 216, 955, 621, 343, 361
};

int verify_data[DATA_SIZE] =
{
    0, 454, 454, 564, 335, 187, 187, 749, 749, 365, 365, 350, 132, 132, 153, 584, 216, 584, 216, 621,
  210, 210, 210, 572, 572, 890, 593, 593, 593, 694, 694, 694, 228, 110, 110, 116, 750, 296, 646, 426,
  500, 426, 436, 436, 659, 701, 774, 774, 812, 678, 678, 678, 696, 696, 564, 474, 474, 474, 272, 539,
  539, 569, 569, 509, 203, 203, 280, 703, 703, 669, 606, 511, 511, 551, 657, 657, 592, 195, 569, 267,
  569, 267, 800, 337, 584, 584, 643, 902, 643, 368, 368, 489, 489, 826, 328, 826, 592, 933, 592, 388,
  388, 543, 649, 649, 649, 566, 979, 649, 814, 657, 657, 181, 181, 181, 208, 859, 859, 629, 629, 288,
  704, 349, 704, 349, 253, 253, 715, 886, 715, 430, 415, 415, 538, 576, 700, 761, 700, 241, 241, 478,
  478, 478, 499, 499, 693, 403, 416, 416, 416, 444, 296, 676, 620, 620, 317, 224, 224, 351, 540, 540,
  540, 288, 169, 169, 527, 606, 527, 389, 389, 389, 796, 455, 720, 455, 720, 367, 745, 367, 358, 358,
  584, 584, 271, 271, 853, 853, 788, 403, 531, 517, 517, 517, 461, 559, 461, 775, 358, 358, 332, 332,
  684, 684, 684, 598, 446, 143, 311, 125, 311, 743, 743, 933, 557, 799, 557, 557, 557, 553, 796, 648,
  648, 648, 891, 891, 666, 287, 514,  49, 514,  86, 557,  95, 853, 441, 441, 441, 440, 587, 614, 614,
  396, 382, 280, 280,  17, 808, 170, 819, 291, 344, 344, 380, 450, 512, 512, 512, 917, 917, 539, 539,
  808, 882, 887, 882, 537, 537, 612, 701, 701, 701, 479, 479, 479, 567, 151,  22,  22, 568, 568, 568,
  665, 665, 423, 423, 434, 434, 280, 158, 280,  84, 395, 247, 688, 247, 476, 435, 476, 792, 792, 792,
  729, 486, 265, 414, 236, 369, 236, 369, 214, 518, 180, 518, 503, 682, 596, 596, 284, 264, 264, 499,
  499, 346, 346, 599, 599, 215, 215, 731, 731, 688, 658, 619, 251, 251, 131, 555, 555, 555, 667, 528,
  528, 528, 487, 487, 487, 753, 753, 287, 287, 626, 626, 304,  14, 304, 403, 733, 403, 733, 703, 703,
  703, 722, 818, 722, 406, 406, 874, 874, 856, 748, 748,  91,  86,  91, 378, 378, 660, 105, 153, 153,
  153, 381, 121, 651, 412, 825, 412, 356, 236, 148, 148, 148, 423, 140, 216, 216, 621, 621, 361,   0
};

