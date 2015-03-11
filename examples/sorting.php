<?php

spl_autoload_register(function($classname){
    $path = __DIR__ . '/../classes/' .
        str_replace(['_', '\\'], DIRECTORY_SEPARATOR, $classname) . '.php';

    if (file_exists($path)) {
        echo $path . PHP_EOL;
        include $path;
    }
});

class FooIterator
    implements BidirectionalSeekableIterator
{
    /**
     * @var SortableCollection
     */
    private $internalCollection;

    /**
     * @var int
     */
    private $currentIndex;

    /**
     * @var mixed[]
     */
    private $internalCollectionKeys;

    /**
     * @var int
     */
    private $lastItem;

    /**
     * @param SortableCollection $collection
     */
    public function __construct(SortableCollection $collection)
    {
        $this->internalCollection = $collection;
        $this->currentIndex = 0;
        $this->internalCollectionKeys = $collection->keys();
        $this->lastItem = count($collection) - 1;
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
        return $this->internalCollectionKeys[$this->index()];
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
     * @return void
     */
    public function end()
    {
        $this->currentIndex = $this->lastItem;
    }

    /**
     * @param int $position
     * @return void
     */
    public function seek($position)
    {
        if ($position > $this->lastItem || $position < 0) {
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
     * @param int $position
     * @return void
     */
    public function previous($position = 1)
    {
        $this->seek($this->currentIndex - $position);
    }

    /**
     * @param int $position
     * @return void
     */
    public function next($position = 1)
    {
        $this->seek($this->currentIndex + $position);
    }
}

class Foo
    implements SortableCollection, ArrayAccess
{
    /**
     * Public for demonstration purposes only
     *
     * @var array
     */
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
        $iterator->rewind();
        return $iterator;
    }

    /**
     * @return BidirectionalSeekableIterator
     */
    public function last()
    {
        $iterator = $this->getIterator();
        $iterator->end();
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
    extends CollectionSorter
{
    /**
     * @param BidirectionalSeekableIterator $left
     * @param BidirectionalSeekableIterator $right
     * @return bool
     */
    public function compare(
        BidirectionalSeekableIterator $left,
        BidirectionalSeekableIterator $right
    ) {
        return (bool) ($left->current() < $right->current());
    }
}

class ReverseSorter
    extends CollectionSorter
{
    /**
     * @var CollectionSorter
     */
    private $internal;

    public function __construct(CollectionSorter $internal)
    {
        $this->internal = $internal;
    }

    /**
     * @param BidirectionalSeekableIterator $left
     * @param BidirectionalSeekableIterator $right
     * @return bool
     */
    public function compare(
        BidirectionalSeekableIterator $left,
        BidirectionalSeekableIterator $right
    ) {
        return !$this->internal->compare($left, $right);
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
$reverseSorter = new ReverseSorter($sorter);

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

    printf('Standard: (%fus / %fus) [%s]' . PHP_EOL, ($nativeEnd - $nativeStart) * 1000000, ($end - $start) * 1000000, implode(', ', $original));

    assert($collection->internal === [1, 2, 3, 4, 5, 6, 7],
        sprintf('Test %d failed, [%s] => [%s].', $i, implode(', ', $original), implode(', ', $collection->internal)));

    $start = microtime(true);
    $reverseSorter->sort($collection);
    $end = microtime(true);

    printf('Reverse:  (%fus / %fus) [%s]' . PHP_EOL, ($nativeEnd - $nativeStart) * 1000000, ($end - $start) * 1000000, implode(', ', $original));

    assert($collection->internal === [7, 6, 5, 4, 3, 2, 1],
        sprintf('Test %d failed, [%s] => [%s].', $i, implode(', ', $original), implode(', ', $collection->internal)));
}

