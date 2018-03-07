#/bin/bash

lspci -nn | grep VGA | while read oneline
do
  get_id
done
