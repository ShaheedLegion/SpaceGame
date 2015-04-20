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

#ifndef UI_VIEWS_LINEAR_SIZER_VIEW_H_
#define UI_VIEWS_LINEAR_SIZER_VIEW_H_

#include "ui/views/group_view.h"

namespace ui {

class LinearSizerView : public GroupView {
public:
  enum OrientationType {
    OrientationHorizontal,
    OrientationVertical,
  };

  explicit LinearSizerView(Context* context);
  LinearSizerView(Context* context, OrientationType orientation);
  virtual ~LinearSizerView();

  // orientation
  OrientationType GetOrientation() const { return m_orientation; }
  void SetOrientation(OrientationType orientation);

  // Override: GroupView
  virtual sf::Vector2i calculateMinSize() const override;
  virtual void layout(const sf::IntRect& rect) override;

private:
  void layoutHorizontal(const sf::IntRect& rect);
  void layoutVertical(const sf::IntRect& rect);

  // The orientaion of the sizer.
  OrientationType m_orientation;

  DISALLOW_IMPLICIT_CONSTRUCTORS(LinearSizerView);
};

}  // namespace ui

#endif  // UI_VIEWS_LINEAR_SIZER_VIEW_H_