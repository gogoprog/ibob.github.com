---
layout: page
title: Test 1
permalink: test.html
comments: true
forcecomments: true
---

* url: {{page.url}}
* id: {{page.id}}
* path: {{page.path}}

Text can be **bold**, _italic_, or ~~strikethrough~~.

[Link to another page](about).

There should be whitespace between paragraphs.

There should be whitespace between paragraphs. We recommend including a README, or a file with information about your project.

# [](#header-1)Header 1

This is a normal paragraph following a header. GitHub is a code hosting platform for version control and collaboration. It lets you and others work together on projects from anywhere.

## [](#header-2)Header 2

{% comment %}
> This is a blockquote following a header.
>
> When something is important enough, you do it even if the odds are not in your favor.
{% endcomment %}

No. Damn. Blockquotes.

### [](#header-3)Header 3

```js
// Javascript code with syntax highlighting.
var fun = function lang(l) {
  dateformat.i18n = require('./lang/' + l)
  return true;
}
```

```ruby
# Ruby code with syntax highlighting
GitHubPages::Dependencies.gems.each do |gem, version|
  s.add_dependency(gem, "= #{version}")
end
```

```c++
// C++ also works?
template <typename Mixin, typename Message>
bool has_next_bidder(Mixin* mixin, Message* message)
{
    internal::mixin_type_info& mixin_info = _dynamix_get_mixin_type_info(mixin);
    auto& msg = static_cast<const internal::message_t&>(_dynamix_get_mixin_feature_fast(message));
    const object* obj = object_of(mixin);
    const internal::object_type_info::call_table_entry& entry = obj->_type_info->_call_table[msg.id];

    if (!entry.top_bid_message) return false;

    if (msg.mechanism == internal::message_t::unicast)
    {
        auto ptr = entry.begin;
        if (!ptr) return false;
        while ((*ptr++)->_mixin_id != mixin_info.id) DYNAMIX_ASSERT(ptr < entry.end);
        return ptr < entry.end;
    }
    else
    {
        auto ptr = entry.begin;
        while ((*ptr++)->_mixin_id != mixin_info.id);
        if (!ptr) return false;
        const internal::message_for_mixin* prev_msg_data = *(ptr - 1);
        while ((*ptr)->bid == prev_msg_data->bid) ++ptr;
        return !!ptr;
    }
}
```

#### [](#header-4)Header 4

*   This is an unordered list following a header.
*   This is an unordered list following a header.
*   This is an unordered list following a header.

##### [](#header-5)Header 5

1.  This is an ordered list following a header.
2.  This is an ordered list following a header.
3.  This is an ordered list following a header.

###### [](#header-6)Header 6

| head1        | head two          | three |
|:-------------|:------------------|:------|
| ok           | good swedish fish | nice  |
| out of stock | good and plenty   | nice  |
| ok           | good `oreos`      | hmm   |
| ok           | good `zoute` drop | yumm  |

### There's a horizontal rule below this.

* * *

### Here is an unordered list:

*   Item foo
*   Item bar
*   Item baz
*   Item zip

### And an ordered list:

1.  Item one
1.  Item two
1.  Item three
1.  Item four

### And a nested list:

- level 1 item
  - level 2 item
  - level 2 item
    - level 3 item
    - level 3 item
- level 1 item
  - level 2 item
  - level 2 item
  - level 2 item
- level 1 item
  - level 2 item
  - level 2 item
- level 1 item

### Small image

![](https://assets-cdn.github.com/images/icons/emoji/octocat.png)

### Large image

![](https://guides.github.com/activities/hello-world/branching.png)


### Definition lists can be used with HTML syntax.

<dl>
<dt>Name</dt>
<dd>Godzilla</dd>
<dt>Born</dt>
<dd>1952</dd>
<dt>Birthplace</dt>
<dd>Japan</dd>
<dt>Color</dt>
<dd>Green</dd>
</dl>

```
Long, single-line code blocks should not wrap. They should horizontally scroll if they are too long. This line should be long enough to demonstrate this.
```

```
The final element.
```
