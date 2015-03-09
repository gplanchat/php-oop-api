<?php

class SplArray
    implements SortableCollection, BidirectionalSeekableIterator, Serializable, JsonSerializable, ArrayAccess
{
    const EXTR_OVERWRITE  = EXTR_OVERWRITE;
    const EXTR_IF_EXISTS  = EXTR_IF_EXISTS;
    const EXTR_REFS       = EXTR_REFS;
    const EXTR_SKIP       = EXTR_SKIP;

    const EXTR_PREFIX_ALL       = EXTR_PREFIX_ALL;
    const EXTR_PREFIX_IF_EXISTS = EXTR_PREFIX_IF_EXISTS;
    const EXTR_PREFIX_INVALID   = EXTR_PREFIX_INVALID;
    const EXTR_PREFIX_SAME      = EXTR_PREFIX_SAME;

    /**
     * @param Traversable $keys
     * @param Traversable $values
     * @return array
     */
    public static function combine(Traversable $keys, Traversable $values)
    {}

    /**
     * @param mixed $start
     * @param mixed $end
     * @param integer $step
     * @return array
     */
    public static function range($start, $end, integer $step)
    {}

    /**
     * @param mixed ...$vars
     * @return array
     */
    public static function compact(...$vars)
    {}

    /**
     * @param integer $startIndex
     * @param integer $count
     * @param mixed $value
     * @return array
     */
    public static function fill(integer $startIndex, integer $count, $value)
    {}

    /**
     * @param integer $startIndex
     * @param mixed $value
     * @return array
     */
    public static function fillKeys(array $keys, $value)
    {}

    /**
     * @param integer $case
     * @return array
     */
    public function changeKeyCase(integer $case)
    {}

    /**
     * @param integer $size
     * @param boolean $preserveKeys
     * @return array
     */
    public function chunk(integer $size, boolean $preserveKeys = false)
    {}

    /**
     * @param mixed $columnKey
     * @param mixed $indexKey
     * @return array
     */
    public function column($columnKey, $indexKey = null)
    {}

    /**
     * @return integer
     */
    public function count()
    {}

    /**
     * @return array
     */
    public function countValues()
    {}

    /**
     * @return array
     */
    public function flip()
    {}

    /**
     * @param integer $size
     * @param mixed $value
     * @return array
     */
    public function pad(integer $size, $value)
    {}

    /**
     * @param boolean $preserveKeys
     * @return array
     */
    public function reverse(boolean $preserveKeys = false)
    {}

    /**
     * @param integer $sortFlags
     * @return array
     */
    public function unique(integer $sortFlags = Sortable::SORT_STRING)
    {}

    /**
     * @param mixed $key
     * @return boolean
     */
    public function hasKey($key)
    {}

    /**
     * @param mixed $value
     * @return boolean
     */
    public function has($value)
    {}

    /**
     * @param mixed $value
     * @return mixed
     */
    public function search($value)
    {}

    /**
     * @return array
     */
    public function keys()
    {}

    /**
     * @return array
     */
    public function values()
    {}

    /**
     * @param callable $callback
     * @param mixed $userData
     * @return boolean
     */
    public function walk(callable $callback, $userData = null)
    {}

    /**
     * @param callable $callback
     * @param mixed $userData
     * @return boolean
     */
    public function recursiveWalk(callable $callback, $userData = null)
    {}

    /**
     * @param array ...$mergedArray
     * @return array
     */
    public function merge(array ...$mergedArray)
    {}

    /**
     * @param array ...$mergedArray
     * @return array
     */
    public function recursiveMerge(array ...$mergedArray)
    {}

    /**
     * @param array ...$replacement
     * @return array
     */
    public function replace(array ...$replacement)
    {}

    /**
     * @param array ...$replacement
     * @return array
     */
    public function recursiveReplace(array ...$replacement)
    {}

    /**
     * @param callable $callback
     * @param mixed $userData
     * @return mixed
     */
    public function reduce(callable $callback, $userData)
    {}

    /**
     * @param integer $offset
     * @param integer $length
     * @param boolean $preseveKeys
     * @return mixed
     */
    public function slice(integer $offset, integer $length, boolean $preseveKeys = false)
    {}

    /**
     * @param integer $offset
     * @param integer $length
     * @param array $replacement
     * @return mixed
     */
    public function splice(integer $offset, integer $length, array $replacement = [])
    {}

    /**
     * @param integer $flags
     * @param string $prefix
     * @return integer
     */
    public function extract(integer $flags = SplArray::EXTR_OVERWRITE, string $prefix = null)
    {}

    /**
     * @return number
     */
    public function sum()
    {}

    /**
     * @return number
     */
    public function product()
    {}

    /**
     * @return mixed
     */
    public function current()
    {}

    /**
     * @return mixed
     */
    public function key()
    {}

    /**
     * @return integer
     */
    public function index()
    {}

    /**
     * @param BidirectionalSeekableIterator $leftKey
     * @param BidirectionalSeekableIterator $rightKey
     * @return void
     */
    public function swap(BidirectionalSeekableIterator $leftKey, BidirectionalSeekableIterator $rightKey)
    {}

    /**
     * @return BidirectionalSeekableIterator
     */
    public function first()
    {}

    /**
     * @return BidirectionalSeekableIterator
     */
    public function last()
    {}

    /**
     * @return BidirectionalSeekableIterator
     */
    public function getIterator()
    {}

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return integer
     */
    public function distance(BidirectionalSeekableIterator $friend)
    {}

    /**
     * @param integer $position
     * @param integer $whence
     * @return integer
     */
    public function seek(integer $position, integer $whence = BidirectionalSeekableIterator::SEEK_SET)
    {}

    /**
     * @return void
     */
    public function next()
    {}

    /**
     * @return void
     */
    public function previous()
    {}

    /**
     * @return void
     */
    public function rewind()
    {}

    /**
     * @return boolean
     */
    public function valid()
    {}

    /**
     * @return void
     */
    public function end()
    {}

    /**
     * @return array
     */
    public function pair()
    {}

    /**
     * @return mixed
     */
    public function pop()
    {}

    /**
     * @@param mixed ...$items
     * @return void
     */
    public function push(...$items)
    {}

    /**
     * @return mixed
     */
    public function shift()
    {}

    /**
     * @@param mixed ...$items
     * @return void
     */
    public function unshift(...$items)
    {}

    /**
     * @return mixed
     */
    public function random()
    {}

    /**
     * @param integer $count
     * @return array
     */
    public function randomSlice(integer $count)
    {}

    /**
     * @param mixed $offset
     * @param mixed $value
     * @return void
     */
    public function offsetSet($offset, $value)
    {}

    /**
     * @param mixed $offset
     * @return mixed
     */
    public function offsetGet($offset)
    {}

    /**
     * @param mixed $offset
     * @return void
     */
    public function offsetUnset($offset)
    {}

    /**
     * @param mixed $offset
     * @return boolean
     */
    public function offsetExists($offset)
    {}

    /**
     * @return string
     */
    public function serialize()
    {}

    /**
     * @param string $serialized
     * @return string
     */
    public function unserialize(string $serialized)
    {}

    /**
     * @return string
     */
    public function jsonSerialize()
    {}

    /**
     * @param string $serialized
     * @return string
     */
    public function jsonUnserialize(string $serialized)
    {}
}
