// See LICENSE for license details.

#include <iostream>
#include "htif_hexwriter.h"
#include "memif.h"
#include "elfloader.h"

int main(int argc, char** argv)
{
  if(argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << " <width> <depth> <elf_file>" << std::endl;
    return 1;
  }

  unsigned width = atoi(argv[1]);
  if(width < 8 || (width & (width-1)))
  {
    std::cerr << "width must be at least 8 and a power of 2" << std::endl;
    return 1;
  }

  unsigned depth = atoi(argv[2]);
  if(depth == 0 || (depth & (depth-1)))
  {
    std::cerr << "depth must be nonzero and a power of 2" << std::endl;
    return 1;
  }

  htif_hexwriter_t htif(width, depth);
  memif_t memif(&htif);
  load_elf(argv[3], &memif);
  std::cout << htif;

  return 0;
}
