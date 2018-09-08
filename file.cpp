#include "file.h"

File::File(File &source)
{
  name = source.name;
  permissions = source.permissions;
}
