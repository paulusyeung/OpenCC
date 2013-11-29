/**
 * Open Chinese Convert
 *
 * Copyright 2010-2013 BYVoid <byvoid@byvoid.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Conversion.hpp"

using namespace Opencc;

Conversion::Conversion(Segmentation* segmentator) {
  this->segmentator = segmentator;
}

shared_ptr<vector<string>> Conversion::Segment(const string& text) {
  shared_ptr<vector<string>> segments;
  segments.reset(new vector<string>);
  for (auto entry : *segmentator->Segment(text)) {
    segments->push_back(entry->key);
  }
  return segments;
}

string Conversion::Convert(const string& text) {
  auto segments = segmentator->Segment(text);
  std::ostringstream buffer;
  for (auto segment : *segments) {
    buffer << segment->GetDefault();
  }
  return buffer.str();
}
