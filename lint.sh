#!/bin/bash
find -E . -regex '.*\.(cc|h)' -exec clang-format -style=Google -i {} \; -exec cpplint {} \;
