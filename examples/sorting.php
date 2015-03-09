<?php

interface Sortable {}

interface CollectionSorter
{
    /**
     * @param SortableCollection $collection
     * @return SortableCollection
     */
    public function sort(SortableCollection $collection);
}

interface SortableCollection
    extends IteratorAggregate, Sortable, Countable
{
    /**
     * @param BidirectionalSeekableIterator $leftKey
     * @param BidirectionalSeekableIterator $rightKey
     * @return void
     */
    public function swap(BidirectionalSeekableIterator $leftKey, BidirectionalSeekableIterator $rightKey);

    /**
     * @return BidirectionalSeekableIterator
     */
    public function first();

    /**
     * @return BidirectionalSeekableIterator
     */
    public function last();

    /**
     * @return BidirectionalSeekableIterator
     */
    public function getIterator();

    /**
     * @return array
     */
    public function keys();
}

/**
 * Note: extends Iterator instead of SeekableIterator due to E_STRICT thrown when a 2nd parameter is added to seek()
 */
interface BidirectionalSeekableIterator
    extends /* SeekableIterator*/ Iterator
{
    const SEEK_SET = 0;
    const SEEK_CUR = 1;
    const SEEK_END = 2;

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return int
     */
    public function distance(BidirectionalSeekableIterator $friend);

    /**
     * @param int $position
     * @param int $whence
     * @return void
     */
    public function seek($position, $whence);

    /**
     * @return void
     */
    public function previous();

    /**
     * @return void
     */
    public function next();

    /**
     * @return integer
     */
    public function index();
}

class FooIterator
    implements BidirectionalSeekableIterator
{
    private $internalCollection;

    private $currentIndex;

    public function __construct(SortableCollection $collection)
    {
        $this->internalCollection = $collection;
        $this->currentIndex = 0;
    }

    /**
     * @return integer
     */
    public function index()
    {
        return $this->currentIndex;
    }

    /**
     * @return mixed Can return any type.
     */
    public function current()
    {
        return $this->internalCollection[$this->key()];
    }

    /**
     * @return mixed scalar on success, or null on failure.
     */
    public function key()
    {
        $keys = $this->internalCollection->keys();
        return $keys[$this->index()];
    }

    /**
     * @return bool
     */
    public function valid()
    {
        return $this->index() < $this->internalCollection->count();
    }

    /**
     * @return void
     */
    public function rewind()
    {
        $this->currentIndex = 0;
    }

    /**
     * @param int $position
     * @param int $whence
     * @return void
     */
    public function seek($position, $whence = self::SEEK_SET)
    {
        $limit = count($this->internalCollection) - 1;
        if ($whence === self::SEEK_CUR) {
            $position += $this->currentIndex;
        } else if ($whence === self::SEEK_END) {
            $position = count($this->internalCollection) - $position - 1;
        }
        if ($position > $limit || $position < 0) {
            throw new OutOfRangeException();
        }
        $this->currentIndex = $position;
    }

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return int
     */
    public function distance(BidirectionalSeekableIterator $friend)
    {
        return $friend->index() - $this->index();
    }

    /**
     * @return void
     */
    public function previous()
    {
        $this->seek(-1, self::SEEK_CUR);
    }

    /**
     * @return void
     */
    public function next()
    {
        $this->seek(1, self::SEEK_CUR);
    }
}

class Foo
    implements SortableCollection, ArrayAccess
{
    public $internal;

    /**
     *
     */
    public function __construct()
    {
        $this->internal = func_get_args();
    }

    /**
     * @param BidirectionalSeekableIterator $start
     * @param BidirectionalSeekableIterator $end
     * @return array
     */
    public function dump(BidirectionalSeekableIterator $start, BidirectionalSeekableIterator $end)
    {
        return array_slice($this->internal, $start->index(), $start->distance($end));
    }

    /**
     * @param BidirectionalSeekableIterator $leftKey
     * @param BidirectionalSeekableIterator $rightKey
     * @return void
     */
    public function swap(BidirectionalSeekableIterator $leftKey, BidirectionalSeekableIterator $rightKey)
    {
        $tmp = $this->internal[$leftKey->key()];
        $this->internal[$leftKey->key()] = $this->internal[$rightKey->key()];
        $this->internal[$rightKey->key()] = $tmp;
    }

    /**
     * @return BidirectionalSeekableIterator
     */
    public function first()
    {
        $iterator = $this->getIterator();
        $iterator->seek(0, BidirectionalSeekableIterator::SEEK_SET);
        return $iterator;
    }

    /**
     * @return BidirectionalSeekableIterator
     */
    public function last()
    {
        $iterator = $this->getIterator();
        $iterator->seek(0, BidirectionalSeekableIterator::SEEK_END);
        return $iterator;
    }

    /**
     * @return BidirectionalSeekableIterator
     */
    public function getIterator()
    {
        return new FooIterator($this);
    }

    /**
     * @param mixed $offset
     * @return bool
     */
    public function offsetExists($offset)
    {
        return isset($this->internal[$offset]);
    }

    /**
     * @param mixed $offset
     * @return mixed Can return all value types.
     */
    public function offsetGet($offset)
    {
        return $this->internal[$offset];
    }

    /**
     * @param mixed $offset
     * @param mixed $value
     * @return void
     */
    public function offsetSet($offset, $value)
    {
        $this->internal[$offset] = $value;
    }

    /**
     * @param mixed $offset
     * @return void
     */
    public function offsetUnset($offset)
    {
        unset($this->internal[$offset]);
    }

    /**
     * @return integer
     */
    public function count()
    {
        return count($this->internal);
    }

    /**
     * @return array
     */
    public function keys()
    {
        return array_keys($this->internal);
    }
}

class UserlandQuickSortAlgorithmSorter
    implements CollectionSorter
{
    public function sort(SortableCollection $collection)
    {
        $start = $collection->first();
        $end = $collection->last();

        $this->quickSort($collection, $start, $end);
    }

    public function quickSort(
        SortableCollection $collection,
        BidirectionalSeekableIterator $start,
        BidirectionalSeekableIterator $end
    ) {
        if ($start->distance($end) > 0) {
            $pivot = $this->partition($collection, $start, $end);

            $tmp = clone $pivot;
            if ($start->distance($tmp) > 1) {
                $tmp->previous();
                $this->quickSort($collection, $start, $tmp);
            } else if ($this->compare($pivot, $start)) {
                $collection->swap($pivot, $start);
            }

            $tmp = clone $pivot;
            if ($tmp->distance($end) > 1) {
                $tmp->next();
                $this->quickSort($collection, $tmp, $end);
            } else if (!$this->compare($pivot, $end)) {
                $collection->swap($end, $pivot);
            }
        }
    }

    private function compare(
        BidirectionalSeekableIterator $left,
        BidirectionalSeekableIterator $right
    ) {
        return (bool) ($left->current() < $right->current());
    }

    private function partition(
        SortableCollection $collection,
        BidirectionalSeekableIterator $first,
        BidirectionalSeekableIterator $last
    ) {
        $pivot = clone $first;
        $pivot->seek(ceil($first->distance($last) / 2), BidirectionalSeekableIterator::SEEK_CUR);

        $collection->swap($pivot, $last);

        $wall = clone $first;
        $iterator = clone $first;
        while ($iterator->distance($last) >= 1) {
            if ($this->compare($iterator, $last)) {
                $collection->swap($wall, $iterator);
                $wall->next();
            }
            $iterator->next();
        }
        $collection->swap($wall, $last);

        return $wall;
    }
}

$collections = [];
$collections[] = new Foo(1, 2, 3, 4, 5, 6, 7);
$collections[] = new Foo(7, 1, 2, 3, 4, 5, 6);
$collections[] = new Foo(6, 7, 1, 2, 3, 4, 5);
$collections[] = new Foo(5, 6, 7, 1, 2, 3, 4);
$collections[] = new Foo(4, 5, 6, 7, 1, 2, 3);
$collections[] = new Foo(3, 4, 5, 6, 7, 1, 2);
$collections[] = new Foo(2, 3, 4, 5, 6, 7, 1);

$collections[] = new Foo(7, 6, 5, 4, 3, 2, 1);
$collections[] = new Foo(1, 7, 6, 5, 4, 3, 2);
$collections[] = new Foo(2, 1, 7, 6, 5, 4, 3);
$collections[] = new Foo(3, 2, 1, 7, 6, 5, 4);
$collections[] = new Foo(4, 3, 2, 1, 7, 6, 5);
$collections[] = new Foo(5, 4, 3, 2, 1, 7, 6);
$collections[] = new Foo(6, 5, 4, 3, 2, 1, 7);

$collections[] = new Foo(3, 1, 2, 5, 4, 7, 6);
$collections[] = new Foo(6, 1, 2, 5, 4, 7, 3);
$collections[] = new Foo(1, 2, 3, 4, 5, 6, 7);
$collections[] = new Foo(4, 1, 6, 7, 3, 2, 5);
$collections[] = new Foo(7, 6, 5, 4, 2, 1, 3);
$collections[] = new Foo(2, 6, 3, 4, 1, 5, 7);
$collections[] = new Foo(5, 3, 7, 1, 4, 2, 6);
$collections[] = new Foo(3, 6, 2, 5, 1, 7, 4);
$collections[] = new Foo(3, 6, 2, 5, 1, 7, 4);
$collections[] = new Foo(4, 3, 2, 7, 1, 5, 6);

$sorter = new UserlandQuickSortAlgorithmSorter();

$i = 0;
foreach ($collections as $collection) {
    $i++;

    $original = $collection->internal;
    $native = $collection->internal;

    $nativeStart = microtime(true);
    sort($native);
    $nativeEnd = microtime(true);

    $start = microtime(true);
    $sorter->sort($collection);
    $end = microtime(true);

    printf('(%fus / %fus) [%s]' . PHP_EOL, ($nativeEnd - $nativeStart) * 1000000, ($end - $start) * 1000000, implode(', ', $original));

    assert($collection->internal === [1, 2, 3, 4, 5, 6, 7],
        sprintf('Test %d failed, [%s] => [%s].', $i, implode(', ', $original), implode(', ', $collection->internal)));
}

