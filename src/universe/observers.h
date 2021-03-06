// Copyright (c) 2015, Tiaan Louw
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef UNIVERSE_OBSERVERS_H_
#define UNIVERSE_OBSERVERS_H_

class Object;

// Observer that is notified when an object is about to be removed from the
// universe.
class RemoveObjectObserver {
public:
  virtual ~RemoveObjectObserver();

  // This is called before the object is deleted.
  virtual void onRemovingObject(Object* object) = 0;

  // This is called after the object is deleted.  So don't access object.
  virtual void onObjectRemoved(Object* object) = 0;
};

#endif  // UNIVERSE_OBSERVERS_H_
